#include <stdio.h>
#include <stdlib.h>
#include <time.h>



class Array
{
private:
	int *arr;
	int size;
public:
	Array(int i)
	{
		arr = new int [i];
		size = i;
	}
	~Array()
	{
		delete arr;
	}	
	
	inline int get_size(void)
	{
		return size;
	}

	inline int get(int pos)
	{
		return arr[pos];
	}
	
	inline void set(int x, int val)
	{
		arr[x] = val;	
	}

	void swap(int posx, int posy)
	{
		int tmp;
		tmp = arr[posx];
		arr[posx] = arr[posy];
		arr[posy] = tmp;	
	}

	int init(void);	
	int display(void);	
};

int Array::display(void)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("%d %d \n",i , arr[i]);	
}

int Array::init(void)
{
	int i;
	
	for(i = 0; i < size; i++)
		arr[i] = rand()%(1001);	
}


class Sort
{
public:	
	virtual void sort(class Array *) =0;
};


class Bblsrt : public Sort
{
public:
	void sort(class Array *);		
};


void Bblsrt::sort(class Array *obj)
{
	int i, j;
	int size = obj->get_size();

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < ((size-1)-i); j++)
		{
			if(obj->get(j+1) < obj->get(j))	
			{
				obj->swap(j+1,j);	
			}
		}
	}			
}

class Engine
{
private:
	struct timespec time;
public:
	long get_time(void);
};

long Engine::get_time(void)
{
	clock_gettime(CLOCK_MONOTONIC, &time);
	return time.tv_nsec;
}

class Bblsrt bbl;

class Sort *srt[] = {
	&bbl,
	NULL
};

int main(int argc, char **argv)
{
	long t1, t2;

	class Engine tobj;	
	int size = atoi(argv[1]);
	class Array obj(size);	
	
	obj.init();	

	t1 = tobj.get_time();
	srt[0]->sort(&obj);
	t2 = tobj.get_time();

//	obj.display();
	
	printf("time taken = %ld \n", t2 - t1);

	return 0;
}
