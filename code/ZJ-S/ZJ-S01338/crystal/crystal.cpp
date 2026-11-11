#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],maxx=0;
void A(int x1,int m,int maxn,int minn){
	int x=x1,cnt=1;
	while(m-x>=0&&maxn>minn){
		cnt++;
		x+=x1;
		maxn-=x1;
		m-=x;
	}
	cout<<cnt;
}
void f(int op,int m){
	int cnt=1;
	for(int i=op-1;i>=1;i--){
		if(m-(a[op]-a[i])>=0){
			cnt++;
			m-=(a[op]-a[i]);
		}
		maxx=max(maxx,cnt);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	int x1=a[2]-a[1],x2=1;
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]==x1)
			x2++;
	if(x2==n-1){
		A(x1,m,a[n],a[1]);
		return 0;
	}
	
	for(int i=2;i<=n;i++)
		f(i,m);
	cout<<maxx;
	return 0;
}
