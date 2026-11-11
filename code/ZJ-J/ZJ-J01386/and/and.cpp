#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2005;
long long a[N];
long long maxx=-1;
void zhao(int i,long long sum,int s){
	if(s==0){
		maxx=max(maxx,sum);
		return;
	}
	if(i>n) return;
	if(s==m){
		zhao(i+1,a[i],s-1);
		zhao(i+1,0,s);
		return;
	}
	zhao(i+1,sum&a[i],s-1);
	zhao(i+1,sum,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		zhao(1,0,m);
		cout<<maxx;
		return 0;
	}
	if(m==1){
		long long maxx2=-1;
		for(int i=1;i<=n;i++){
			maxx2=max(maxx2,a[i]);
		}
		cout<<maxx2;
		return 0;
	}
	if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(i==1) ans=a[i];
			else ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long maxx2=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx2=max(maxx2,a[i]&a[j]);
			}
		}
		cout<<maxx2;
	}
}
