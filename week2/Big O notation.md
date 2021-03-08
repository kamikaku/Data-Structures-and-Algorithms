# Big O 表示法
---
**big O**表示法其实就是用来描述算法的时间复杂度的一种表示方法。

* $O(1)$
* $O(logn)$
* $O(n)$
* $O(nlogn)$
* $O(n^2)$
* $O(n^3)$
* $O(2^n)$
* $O(n!)$

上方列表中,复杂度从上往下依次增高。  
***
进一步的说明则是,有两个由非负数函数$f(n)$与$g(n)$其中$n>0$。当$\frac{f(n)}{g(n)}<0$时,称$f(n)$的增长速度比$g(n)$慢(slower than),写作$f \prec g$。
若存在常数$c$,满足$f(n)\leq c\cdot g(n)$,写作$f \preceq g$, 称称$f(n)$的增长速度不比$g(n)$快(no faster than)。
以下有三个重点:
* $f \prec g$ 记作 $f=o(g)$; 而$f \preceq g$ 记作$f=O(g)$
* 若满足$f \prec g$, 则必然满足$f \preceq g$
* 在进行标记时,使用的是花体的$\prec$与$\preceq$, 而非正常的$ < $与 $\le$