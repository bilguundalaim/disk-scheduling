#include "disk.h"

void fcfs(int request[], int head)
{
  int count = 0;
  int distance, current;

  for (int i = 0; i < SIZE; i++)
  {
    current = request[i];
    distance = abs(current - head);
    count += distance;
    head = current;
  }

  printf("FCFS -> %d\n", count);
};

int findMin(int request[], int processed[], int head)
{
  int distances[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    if (processed[i])
    {
      distances[i] = MAX;
    }
    else
    {
      distances[i] = abs(request[i] - head);
    }
  }

  int minIndex = 0;
  for (int i = 1; i < SIZE; i++)
  {
    if (distances[i] < distances[minIndex])
    {
      minIndex = i;
    }
  }

  return minIndex;
}

void sstf(int request[], int head)
{
  int count = 0;
  int distance, current, minIndex;
  int processed[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    processed[i] = 0;
  }

  for (int i = 0; i < SIZE; i++)
  {
    minIndex = findMin(request, processed, head);
    current = request[minIndex];
    distance = abs(head - current);
    count += distance;
    head = current;
    processed[minIndex] = 1;
  }

  printf("SSTF -> %d\n", count);
};

void scan(int request[], int head)
{
  int count = 0;
  int startPoint = head;
  int distance, current;
  int processed[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    processed[i] = 0;
  }

  for (int i = startPoint; i >= 0; i--)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (processed[j] == 0 && request[j] == i)
      {
        current = request[j];
        distance = abs(head - current);
        count += distance;
        head = current;
        processed[j] = 1;
      }
    }
  }

  for (int i = 0; i < CYLINDER; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (processed[j] == 0 && request[j] == i)
      {
        current = request[j];
        distance = abs(head - current);
        count += distance;
        head = current;
        processed[j] = 1;
      }
    }
  }

  printf("SCAN -> %d\n", count);
};

void c_scan(int request[], int head){

};
