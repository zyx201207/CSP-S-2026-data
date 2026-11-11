#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	sort(a+1,a+1+n);
	long long v[N];
	for(long long i=a[1];i<=a[n];i++){
		long long c=m;
		memset(v,0,sizeof(v));
		for(long long j=1;j<=n;j++){
			if(a[j]>i) v[j]=-1;
			else v[j]=i-a[j];
		}
		long long tmp=0;
		for(long long j=1;j<=n;j++){
			if(v[j]==-1) break;
			if(c-v[j]>=0){
				c-=v[j];
				tmp++;
			}
		} 
		ans=max(ans,tmp);
	}
	cout<<ans;
	//bjy
}

