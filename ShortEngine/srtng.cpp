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
		delete[] arr;
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
	virtual void name(void) =0;
};


class Mergesrt : public Sort
{

private :
	
	void merge_sort(class Array *,int ,int);
	void merge(class Array*,int ,int ,int);
public :

	int *healper;	
	void sort(class Array *);
	void name(void)
	{
		printf("Vipin mergesort\n");
	}

	~Mergesrt()
	{
	delete[] healper;
	}
};




void Mergesrt::sort(class Array *arr)
{	
	healper=new int[arr->get_size()];
	merge_sort(arr,0,arr->get_size()-1);
}



void Mergesrt::merge_sort(class Array *arr,int l,int h)
{

if(l<h)
{		
int mid=(l+h)/2;
merge_sort(arr,l,mid);
merge_sort(arr,mid+1,h);
merge(arr,l,mid,h);

}

}



void Mergesrt::merge(class Array *arr,int low,int mid,int high)
{


int k=low,n=mid+1,p=low;

while(k<=high)
	{
		healper[k]=arr->get(k);
		k++;
	}



		k=low;

while(k<=mid && n<=high)
	{

		if(healper[k]<healper[n])
		{
			arr->set(p,healper[k]);
			k++;
		}
		else
		{
			arr->set(p,healper[n]);
			n++;
		}
		p++;
	}

while(k<=mid)
	{
		arr->set(p,healper[k]);
		k++;p++;
	}

}

class Bblsrt : public Sort
{
public:
	void sort(class Array *);
	void name(void)
	{	
		printf("Ankit Bblsrt\n");
	}		
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


class Qcksrt : public Sort
{
private:
	int partition(class Array *, int , int);
	int quick_sort(class Array* , int, int);		
public:
	void name(void)
	{
		printf("Ankit Qcksrt\n");
	}		
	
	void sort(class Array *);
};

int Qcksrt::quick_sort(class Array* arr, int start, int end)
{
	int parted;
	if(end > start) {	
		parted = partition(arr, start, end);
		quick_sort(arr, start, parted);
		quick_sort(arr, parted+1, end);
	}

	return 0;
		
}		

int Qcksrt::partition(class Array *arr, int start, int end)
{
	int i = start -1;
	int j;
	int pivot = arr->get(end-1);

	for(j = start; j < end; j++)
	{
		if(arr->get(j) <= pivot) {
			i++;
			arr->swap(j, i);
		}
	}
	
	return i;
}


void Qcksrt::sort(class Array *arr)
{		
	quick_sort(arr, 0, arr->get_size());
}	

class Engine
{
private:
	struct timespec time;
	long get_time(void);
	int chk_srt(class Array *);
public:
	void srt_play(class Sort **, int );
};

int Engine::chk_srt(class Array *obj)
{
	int size = obj->get_size();
	int i;
	
	for(i = 0; i < (size -1); i++) 
		if(obj->get(i) > obj->get(i+1)) { 
			printf("Array was not sorted :(\n");
			return -1;	
		}
	printf("Array was sorted\n");
	return 0;
}

long Engine::get_time(void)
{
	clock_gettime(CLOCK_MONOTONIC, &time);
	return time.tv_nsec;
}

void Engine::srt_play(class Sort **srt, int size)
{
	int i = 0;
	unsigned long t1, t2;
	class Array obj(size);	
	
	if(!srt) {
		printf("No Sorting Obj Provided\n");
		exit(0);
	}

	while(srt[i])
	{
		obj.init();
		//printf("array before sorting");	
		//obj.display();
		t1 = get_time();

		(*(srt+i))->name();
		(*(srt+i))->sort(&obj);

		t2 = get_time();
       
		chk_srt(&obj);
         	//printf("array after sorting");
		//obj.display();
		printf("time taken = %ld \n\n", t2 - t1);
		
		i++;
	}
}

class Bblsrt bbl;
class Qcksrt qck;
class Mergesrt msrt;

class Sort *srt[] = {
	&msrt,
	&bbl,
	&qck,
	NULL
};

int main(int argc, char **argv)
{
	class Engine obj;	
	int size = atoi(argv[1]);
	
	obj.srt_play(srt, size);

	return 0;
}
