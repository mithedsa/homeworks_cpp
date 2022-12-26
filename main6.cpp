#include <iostream>

class SortingStrategy{
public:
    virtual void sort(int *arr, int size) = 0;
    virtual ~SortingStrategy() = default;
};

bool sorted(const int *arr, int size){
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

class BogoSort final : public SortingStrategy{
public:
    void sort(int *arr, int size) override{
        while (!sorted(arr, size)){
            for (int i = 0; i < size; i++)
                std::swap(arr[i], arr[rand() % size]);
        }
    }
};

class InsertionSort final : public SortingStrategy{
public:
    void sort(int *arr, int size) override{
        int i, key, j;
        for (i = 1; i < size; i++){
            key = arr[i];
            j = i - 1;
            while (j >= 0 and arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

class BubbleSort final : public SortingStrategy{
public:
    void sort(int *arr, int size) override{
        int i, j;
        for (i = 0; i < size - 1; i++)
            for (j = 0; j < size - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
    }
};

class SelectionSort final : public SortingStrategy{
public:
    void sort(int *arr, int size) override{
        int i, j, min_idx;
        for (i = 0; i < size - 1; i++){
            min_idx = i;
            for (j = i + 1; j < size; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            if (min_idx != i)
                std::swap(arr[min_idx], arr[i]);
        }
    }
};

class Sort{
    SortingStrategy *strat;
public:
    Sort()=default;
    ~Sort()=default;

    void setStrategy(SortingStrategy * obj){
        this->strat = obj;
    };

    void execSort(int  *arr, int size){
        strat->sort(arr, size);
    }
};


int main(){
    int testsize = 10;
    int testarr[] = {2,1,3,4, 5, 7, 6, 7,9, 10};
    Sort sample;
    SelectionSort that;
    sample.setStrategy(&that);
    sample.execSort(testarr, testsize);
    for (int i = 0; i < testsize; ++i) {
        std::cout<< testarr[i] << ' ';
    }
    return 0;

}