#include <stdio.h>

void gibAus (char *current) {
  printf ("-> %s\n", current);
}

typedef void(*ForEachFunction)(char *);

void forEach (int count, char **arr, ForEachFunction func) {
  for (int i = 0; i < count; i++) {
    func (arr[i]);
  }
}

int main (int argc, char **argv) {
  
  forEach (argc, argv, gibAus);
  
}
