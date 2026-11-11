#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char c[N];//第i个字母 
long long x[N];//记录第i个字母共出现了几次 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;//记录有几个不一样的字符 
	deque <char> s;//有数值 
	deque <char> m;
	for(int i=1;i<=n;i++){
		int a;
		char cc;
		cin>>a>>cc;
		if(cc==c[i-1]){//如果字符和上一个字符一样 
			x[i-1]+=a; 
		}else{
			len++;
			c[len]=cc;//记录字符
			x[len]=a;//记录数量 
		}
	}
	deque<char> a;
	deque<char> b;
	for(int i=1;i<=len;i++){
		for(int j=1;j<=x[i];j++){
			a.push_back(c[i]);
			b.push_front(c[i]);
		}
	}
	int sum=0;
	for(int i=1;i<=(len+1)/2;i++){
		char c1=a.front(),c2=b.front();
		if(c1!=c2) 
			sum++;
	}
	cout<<sum;
	return 0;
} 
