#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0,l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];b=max(b,a[i]);}
	if(m==1)cout<<b;
	else if(m==2){
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if((a[i] & a[j])>l)l=a[i] & a[j];
		cout<<l;
	}
	else {
		l=a[1];
		for(int i=2;i<=n;i++)l=l & a[i];
		cout<<l;
	}
	return 0;
}
