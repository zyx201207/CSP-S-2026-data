#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=2e5+5;
struct LR{
	int len;
	string val;
}a[M];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].len>>a[i].val;
	int p=1,q=n;
	while(p<q){
		int del=min(a[p].len,a[q].len);
		if(a[p].val[0]!=a[q].val[0])ans+=del;
		a[p].len-=del;if(!a[p].len)p++;
		a[q].len-=del;if(!a[q].len)q--;
	}
	cout<<ans<<"\n";
}
