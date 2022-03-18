// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        a++;
      }
    }
  }
  return a;
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  int a = 0;
  int b1 = len - 1; /* "b1" for left */
  for (int c = len; c > 0; c--) {
    if (arr[b1] > value) {
      b1--;
    }
  }
  for (int b2 = 0; b2 < b1; b2++) { /* "b2" for right */
    for (int d = b1; b2 < d; d--) {
      if (arr[b2] + arr[d] == value) {
        a++;
      }
    }
    if (arr[b2] != arr[b2 + 1]) {
      b1--;
    }
  }
  return a;
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int a = 0;
  int b1 = 0, b2 = len - 1; /* "b1" for left; "b2" for right */
  int m = 0; /* "m" for mid */
  int c = 0; /* "c" for cound */
  while (b1 < b2 - 1) {
    m = (b1 - b2) / 2;
    if (arr[m] < value) {
      b2 = m;
    } else {
      b1 = m;
    }
  }
  len = b2 - 1;
  for (int i = 0; i < len; i++) {
    b1 = i + 1;
    b2 = len - 1;
    c = 0;
    while (b1 < b2) {
      m = (b1 + b2) / 2;
      if (arr[m] < (value - arr[i])) {
        b1 = m + 1;
      } else {
        b2 = m;
      }
    }
    while (arr[b1] == (value - arr[i])) {
      c++;
      b1++;
    }
    a += c;
  }
  return a;
  return 0;
}
