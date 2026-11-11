#include<bits/stdc++.h>
using namespace std;
unsigned long long sum,q,ans,s;
long long n,l,r,p,a[208888],d[208888];
char c[208888],b[1000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i-1];
		cin>>a[i]>>c[i];
		for(int j=d[i];j<=d[i]+a[i]-1;j++){
			b[j]=c[i];
		}
		s+=a[i];
	}
	for(int i=1,j=s;i<=j;i++,j--){
		if(b[i]!=b[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
3 a
1 b 
1 c
*/
