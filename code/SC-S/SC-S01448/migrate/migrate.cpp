#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
const int N=2e6+5;
int c,_,n,m,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
		cin>>n>>m;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fl=0;
		}
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		//暴力
		/*
		if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=n;j>i;j--){
					if(a[j]-a[i]<=m) break;
					int id=lower_bound(a+1,a+1+j,a[j]-m)-a;
					int su=0;
					if(id+1<j&&a[id+1]-a[i]<=m) su++;
					if(id+2<j&&a[id+2]-a[i]<=m) su++;
					if(su==1) ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}*/
		//
		if(fl){
			if(a[3]-a[1]>m) cout<<"0\n";
			else{
				int la=0;
				for(int i=1;i<=n;i++){
					if(a[i]-a[1]>m) break;
					la=i;
				}
				if(la==2) cout<<n-4+1<<'\n';
				else{
					int jie=la+la-2;
					cout<<max(0ll,n-jie+1)<<'\n';
				}
			}
			continue;
		}
		fl=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=m&&a[n]-a[i]<=m) fl=1;
		}
		if(fl){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				if(a[j]-a[i]<=m) break;
				int id=lower_bound(a+1,a+1+j,a[j]-m)-a;
				int su=0;
				if(id+1<j&&a[id+1]-a[i]<=m) su++;
				if(id+2<j&&a[id+2]-a[i]<=m) su++;
				if(su==1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//migrate4.in
// g++ -o2 migrate.cpp -O2 -std=c++14