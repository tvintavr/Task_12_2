#include <iostream>
#include <limits>
#include <math.h>

void sort(float *number, int first, int last)
{
float mid, count;
int f=first, l=last;
mid=number[(f+l) / 2]; //вычисление опорного элемента
do
{
    while (number[f]>mid) {
        f++;
    }
    while (number[l]<mid) {
        l--;
    }
    if (f<=l) //перестановка элементов
    {
        count=number[f];
        number[f]=number[l];
        number[l]=count;
        f++;
        l--;
    }
} while (f<l);
if (first<l) {
    sort(number, first, l);
}
if (f<last) {
    sort(number, f, last);
}
}



int main() {
    
    float number[15];
    int i;

    for (i=0;i<15;i++) {
        bool incorrect=false;
        while (!incorrect) {
            std::cout<<"Введите число #"<<i+1<<": ";
            std::cin>>number[i];
            if (std::cin.fail() || std::cin.peek()!='\n') {
                std::cout<<"Input error\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                incorrect=false;
            } else {
                incorrect=true;
            }
        }
    }

    int first=0; 
    int last=14;
    sort(number, first, last);
    std::cout<<std::endl<<"Результирующий массив: ";
    for (int i=0; i<15; i++) {
        std::cout<<number[i]<<" ";
    }
}
    
    

    


