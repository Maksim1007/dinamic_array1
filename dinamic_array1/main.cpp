#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "������������ ������: ";
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size) 
        {
            std::cout << arr[i] << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_element)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = new_element;
        logical_size++;
        return arr;
    }
    else 
    {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < logical_size; ++i)
        {
            new_arr[i] = arr[i];
        }
        new_arr[logical_size] = new_element;
        logical_size++;
        delete[] arr;
        actual_size = new_actual_size;
        return new_arr;
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    int actual_size;
    std::cout << "������� ����������� ������ �������: ";
    std::cin >> actual_size;

    int* arr = new int[actual_size]; 
    int logical_size = 0;

    std::cout << "������� ���������� ������ �������: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "������! ���������� ������ �� ����� ��������� ����������� ������." << std::endl;
        delete[] arr; 
        return 1; 
    }

   
    for (int i = 0; i < logical_size; ++i)
    {
        std::cout << "������� arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    
    print_dynamic_array(arr, logical_size, actual_size);

    int new_element;
    while (true)
    {
        std::cout << "������� ������� ��� ���������� (0 ��� ������): ";
        std::cin >> new_element;

        if (new_element == 0)
        {
            std::cout << "�������! ��� ������: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        arr = append_to_dynamic_array(arr, logical_size, actual_size, new_element);
        print_dynamic_array(arr, logical_size, actual_size);
    }
    delete[] arr;

    return 0;
}
