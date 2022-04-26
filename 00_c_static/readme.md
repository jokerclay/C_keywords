# static

* In English `static` means "fixed, unchangingm stable, or steady".
* In  Java, `static member` means "a member associated with the type, not an object".
* In C:
    * you can make a golbal variable `static`
    * you can make a local variable `static`
    * you can make a function `static`

* regardless what it's you are declaring a `static`, in C, it affects the **Scope** of variable
* it affects how it exits and where it will be visble

### `static (golbal/function)`
* making a `global variable` or  `function`  `static`, just means that variable or function 
  is only visble with in it's own translation unit.

### `static(local variable)`
* persistent across function calls and only visble within it's function
* you can call this function over and over again, this variable stick around,
  it's doesn't get earsed, it doesn't get reinitialized.


# why we want to use `static`?
* case 1:
    * you have a variable need to be persistent, it need to save state across 
      function calls from one to another.
    * but it's only used by one function, the other function don't know it exits

* case 2:
    * it allows you to try more modular code in C
    * when use `static (golbal variable/ function)` making modules,
    it's won't have name confilct. we can use it independendtly.
    * when I give you my code, I won't worry  my identifiers are 100% unique
    * downside: others easily get confused, which one is being called when

# example

```C
#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    int sum = 0;
    sum += x;
    return sum;
}

int main () {

    printf("%d\n",add(5));

    return 0;
}

/*
output:
5
*/
```

```C
#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    int sum = 0;
    sum += x;
    return sum;
}

int main () {

    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));

    return 0;
}



/*
output:

5
5
5
5
5
5
*/
```
### if we use the `static` keyword
```C
#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    int static sum = 0;
    sum += x;
    return sum;
}

int main () {

    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));

    return 0;
}

/*
output:

5
10
15
20
25
30

*/
```
### the `sum` variable won't be reinitialized when the `add` function be called again
### it's seems like makeing it like a golbal variable, but, we can not call `sum` in main function

```C
#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    int static sum = 0;
    sum += x;
    return sum;
}

int main () {

    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));


    printf("%d\n",sum);

    return 0;
}

error:
static.c: In function ‘main’:
static.c:18:19: error: ‘sum’ undeclared (first use in this function)
   18 |     printf("%d\n",sum);
      |                   ^~~
static.c:18:19: note: each undeclared identifier is reported only once for each function it appears in


```




