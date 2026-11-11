#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e+5;
ll a[N+10];
ll f[N+10];
ll d[N+10];

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m;	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
		f[1]=0;
		d[i]=d[i-1]+f[i]; 
	}	
	
	int cnt=0,i=1,j=i+1;
	ll sum=0;
	while(j<=n){
		if(f[j]*(j-i)+sum<=m){
			sum+=f[j]*(j-i);
			cnt=max(cnt,j-i+1);
			j++;
		}else{
			sum-=(d[j-1]-d[i]);
			if(i==j)	j++;
			i++;
		}
	}
	
	cout<<cnt;
	
	return 0;
}
