#include"bits/stdc++.h"
#define ll long long
using namespace std;

/*
双指针
期望得分：100pts 
*/ 
const int MAXN=1e5*2+5;
int a[MAXN];
char c[MAXN];
int n;
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int num1=a[l],num2=a[r];
		char ch1=c[l],ch2=c[r];
		if(ch1!=ch2){
			//字符不同，替换最小值 
			sum=sum+min(num1,num2);
		}
		//消掉取最大值不动
		if(num2<num1){
			r--;
			a[l]-=num2;
		}else{
			l++;
			a[r]-=num1;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
08:55-09:18 
*/
