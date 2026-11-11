#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1114514;
	int a=INT_MAX;
	int d;
	for(int i=1;i<=n;i++){
		cin>>d;
		a&=d;
		maxn=max(maxn,d);
	}
	if(m==1)cout<<maxn;
	else if(m==n)cout<<a;
	return 0;
}
