#include<bits/stdc++.h>
using namespace std;
long long n , m ;
long long a[500001] ;
long long cha[500001] ;
long long cnt[500001] ;
long long y[500001] ;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=1;
		y[i]=1;
	}
	sort(a+1,a+1+n);
	long long ms=m;
	long long d=1 ;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		if(cha[i]>=m){
			d=i;
			ms=m;
			y[i]=y[i-1]+1;
			continue;
		}
		if(cha[i]>=ms){
			ms-=cha[i];
			int j=d ;
			while(j<=i-1&&ms<=0){
				ms+=cha[j+1];
				j++;
			}
			d=j;
			cnt[i]=y[i-1]+2-d;
			y[i]=y[i-1]+1;
			continue;
		}
		ms-=cha[i];
		if(ms>0){
			cnt[i]=y[i-1]+2-d;
		}
		y[i]=y[i-1]+1;
	}
	long long ans=-1e9;
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
		ans=max(ans,cnt[i]);
	}
	cout<<endl;
	cout<<ans;
	return 0;
} 
