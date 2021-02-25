# 压力测试(Stress Test)

> 压力测试是性能测试的一种，通常是指持续给被测系统增加压力，直到将被测系统<压跨为止>，用来测试系统所能承受的最大压力。

课程从求数列中两数配对的最大乘积(最大配对积)的代码引出压力测试的概念。
### 代码需求如下所示：
* 1 首先输入一个数字n 代表数列中包含数字的数量(length) 
* 2 接着输入n个数字 组成数列 
* 3 最后输出数列中两数相乘的最大值 
---
随后课程给出了两个解决方案。
1是: 
 ```
  long long MaxPairwiseProduct(const vector<int>& numbers){
    int n = numbers.size();
    long long result = 0;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if((long long)(numbers[i]) * numbers[j] > result){
        result = (long long)(numbers[i])*numbers[j];
        }
      }
    }
    return result;
  } 
 ``` 
使用了嵌套的循环依次配对求乘积,时间复杂度较高。`long long`型是因为在测试程序时，如果输入过大的数字会超出int的最大数字范围，导致结果错误。  **但是这种方法没有通过测试**。
***
第2种解决方案为：  
```
long long MaxPairwiseProductFast(const vector<int>& numbers){
  int n = numbers.size();
  int max_index1 = -1;
  for(int i=0; i<n; i++){
    if(max_index1 == -1 || numbers[i]>numbers[max_index1])
      max_index1= i
  }
  int max_index2 = -1;
  for(int j=0; j<n; j++){
    if((numbers[j]!=numbers[max_index1]) && (max_index2 == -1) || numbers[j]>numbers[max_index2])
    max_index2 = j;
  }
  
  long long result = (long long)(numbers[max_index1]) * numbers[max_index2]
  return result;
}
```
这种方案分别取出数列中第一大和第二大的数字的索引，由此得到结果。在复杂度较第一种方案更低。**但这种方案依然没有通过测试**(但其实很容易可以看出在找第二大数字的时候有明显的漏洞)。
***
提交的代码没有通过测试，也不知道是哪组数据的测试没有通过，这时候需要对代码进行压力测试，自行找出使代码出现问题的测试数据。  
**如果两个方案中的代码都是正确的，那么测试的所有结果必然是相同的，反之如果在测试过程中出现结果不同的部分，说明对于这一组测试数据而言，必然是有一个或以上的方案出现了问题**。  
只要找到了使代码出现问题的测试数据，就能够进一步对代码进行分析。  
找寻这样的测试数据的方法如下：  
```
while(true){
  int n = rand() % 10 + 2;
  cout<<n<<'\n';
  vector<int> a;
  for(int i=0; i<n; i++){
    a.push_back(rand() % 10000);
  }
  for(int i=0; i<n; i++){
    cout<<a[i]<<' ';
  }
  cout<<'\n';
  long long res1 = MaxPairwiseProduct(a);
  long long res2 = MaxPairwiseProductFast(a);
  if(res1 != res2){
    cout<<"wrong answer: "<<res1<<' '<<res2<<'\n';
    break;
   }
  else{
    cout<<"OK\n";
  }
  
}
```
通过不断输入长度与数值都不同的随机数列来对代码进行压力测试。


