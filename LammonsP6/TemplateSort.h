#ifndef TEMPLATESORT_H
#define TEMPLATESORT_H

template <class T> class Sort
{
public:
	Sort();
	void Swap(T a, T b);
	void BubbleSort(T a[], int total);
	void Comb11(T a[], int total);
	void Insertion(T a[], int total);
	void Selection(T a[], int total);
	void Shaker(T a[], int total);
};

template <class T>
Sort<T>::Sort()
{}

template<class T>
void Sort<T>::Swap(T a, T b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void Sort <T>::BubbleSort(T a[], int total)
{
	for (int i = total; i > 0; i--)
	{
		bool flipped = false;
		for (int j = 0; j < i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flipped = true;
			}
		}
		if (!flipped)
		{
			return;
		}
	}
	//T temp;
	//int i{ 0 }, j{ 0 };
	//for (i = 0; i < total - 1; ++i)
	//{
	//	for (j = 1; j < total; ++j)
	//	{
	//		if (a[j - 1] > a[j])
	//		{
	//			temp = a[j];
	//			a[j] = a[j - 1];
	//			a[j - 1] = temp;
	//		}
	//	}
	//}
}

template<class T>
void Sort<T>::Comb11(T a[], int total)
{
	double shrinkfactor = 1.3;

	bool flipped = false;
	int gap, top;
	int i, j;

	gap = total;
	do {
		gap = (int)((float)gap / shrinkfactor);
		switch (gap) {
		case 0: // the smallest gap is 1 - bubble sort
			gap = 1;
			break;
		case 9: // this is what makes this Combsort11
		case 10:
			gap = 11;
			break;
		default: break;
		}
		flipped = false;
		top = total - gap;
		for (i = 0; i < top; i++) {
			j = i + gap;
			if (a[i] > a[j]) {
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				flipped = true;
			}
		}
	} while (flipped || (gap > 1));
	// like the bubble and shell sorts we check for a clean pass
}

template<class T>
void Sort<T>::Insertion(T a[], int total)
{
	for (int i = 1; i < total; i++)
	{
		int j = i;
		// needs to be T B
		T B = a[i];
		while ((j > 0) && (a[j - 1] > B))
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = B;
	}
}

template<class T>
void Sort<T>::Selection(T a[], int total)
{
	for (int i = 0; i < total; i++)
	{
		int min = i;
		for (int j = i + 1; j < total; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		T temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

template<class T>
void Sort<T>::Shaker(T a[], int total)
{
	int i = 0;
	int k = total - 1;
	while (i < k) {
		int min = i;
		int max = i;
		int j;
		for (j = i + 1; j <= k; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
			if (a[j] > a[max])
			{
				max = j;
			}
		}
		T temp = a[min];
		a[min] = a[i];
		a[i] = temp;

		if (max == i)
		{
			temp = a[min];
			a[min] = a[k];
			a[k] = temp;
		}
		else {
			temp = a[max];
			a[max] = a[k];
			a[k] = temp;
		}

		i++;
		k--;
	}
}


#endif