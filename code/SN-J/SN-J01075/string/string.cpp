#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,i,j;
long long a,b,num[N], ans;
//i:前方到了第i种字母  j:后方到了第j种字母  a:i当前字母剩余数量  b:j当前字母剩余数量 
char str[N];
void minus_(bool f){
	long long temp = min(a,b);
	a -= temp;
	b -= temp;
	if(f)	ans += temp;
	if(a==0)	a=num[++i];
	if(b==0)	b=num[--j];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int k=1;k<=n;k++)
		scanf("%lld %c",&num[k],&str[k]);
	i=1,a=num[1], j=n,b=num[n];
	while(i<j){
		if(str[i]==str[j])
			minus_(0);
		else
			minus_(1);
	}
	cout<<ans;
	
	return 0;
} 
