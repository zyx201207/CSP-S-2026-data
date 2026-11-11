#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,1,sizeof f);
	int n,m;
	long long mx=0;
	long long x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=30;i++)x*=2;
	for(;x>=1;x/=2){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=x && (x & a[i])>=1 && f[i])sum++;
		}
		if(sum>=m){
			mx+=x;
			for(int i=1;i<=n;i++){
				if(a[i]>=x && (x & a[i])>=1 && f[i]);
				else f[i]=0;
			}
		}
		if(x==1)break;
	}
	cout<<mx;
	return 0;
}