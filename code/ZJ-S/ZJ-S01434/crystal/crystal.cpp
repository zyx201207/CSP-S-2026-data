#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,m,a[N],s,cf[N],qzh[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
	for(int i=1;i<n;i++){
		cf[i]=a[i+1]-a[i];
	}qzh[1]=cf[1];
	//for(int i=1;i<n;i++)cout<<cf[i]<<' ';cout<<'\n'; 
	for(int i=2;i<n;i++){
		qzh[i]=cf[i]+qzh[i-1];
	}//for(int i=1;i<n;i++)cout<<qzh[i]<<' ';cout<<'\n';
	ll now=cf[1];
	for(ll i=1,j=0;;){
		while(now>m){
			now-=qzh[i]-qzh[j];
			j++;
		}
		ans=max(ans,i-j+1);
		if(i==n-1)break;
		now+=cf[i+1]*(i-j+1);
		i++;
	}cout<<ans;
} 
