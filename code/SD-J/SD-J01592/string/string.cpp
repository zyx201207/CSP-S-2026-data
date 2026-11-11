#include <bits/stdc++.h>
using namespace std;

#include <string>

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[2005];
	char c[2005];
	string L;
	long long l=0;//debug 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
//		l+=a[i];
		for(long long j=0;j<a[i];j++){
			L[l+j]=c[i];//debug
		}
		l+=a[i];
	} 

//	cout<<L[2];//测试
	long long cnt=0;
	long long l2=l/2;
	for(long long i=0;i<=l2;i++){
		if(L[i]!=L[l-i-1]) cnt++; 
	}
	cout<<cnt;
}

/*
	定义n 定义a(连续小写英文字母个数)c(小写字母)
	可以求出l(长度)
	定义字符串 L从第零位开始写入 //l+=a[i]是否可行？
	//定义100位 输入c[i]占用0到99 此时l为0+99=99 但是有100个数据 实际输入100次
	可以用定义时l=1然后写入时L[l+j-1]解决 因为l描述长度可行！ //真的可行吗
	//运行尝试一下 
	似乎可行 可是调试我不大会用 //直接打印L不行吗？ 
	定义计数器 
	然后for循环判断第i位是否和倒数第i位相等 i最大为l的一半（最合理） 否时则计数器加1 
	如果最大为一半-1的话 原数为奇数时会导致有1位无法比较
	//如何去取出倒数第i位？
	使用长度l-1求最后一位 当i=0时判断第一（0）位和最后一位 
	所以最后一位可以用l-i-1表示 //吗？ 
	
	样例2未通过 //Debug
	l可以开始时为0，需要修改 
	已修改
	似乎量太大会出现问题
	可能是string越界了 我暂时无法处理 
*/
