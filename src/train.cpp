// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train()
{
  first = nullptr;
  current = nullptr;
  countOp = 0;
}

void Train::addCage(bool light)
{
  Cage* temp = new Cage;
  temp->light = light;
  temp->next = nullptr;
  temp->prev = nullptr;
  if (!first) {
    first = temp;
  } else if (first->next) {
      temp->prev=first->prev;
      temp->next = first;
      first->prev->next = temp;
      first->prev = temp;
    } else {
        temp->prev = first;
        temp->next = first;
        first->prev = temp;
        first->next = temp;
      }
}

int Train::getLength()
{
  int cage_count = 0;
  int result = 0;
  if (!first->light) {
    first->light = true;
  }
  current = first->next;
  ++cage_count;
  ++countOp;
  while (!current->light) {
    current = current->next;
    ++cage_count;
    ++countOp;
  }
  current->light = false;
  result = cage_count;
  while (cage_count) {
    current = current->prev;
    ++countOp;
    --cage_count;
  }
  if (!current->light) {
    return result;
  }
  else {
    getLength();
  }
}

int Train::getOpCount()
{
  return countOp;
}
