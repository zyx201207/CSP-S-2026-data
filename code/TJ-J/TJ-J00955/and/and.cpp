#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
long long ans,sum;
void dfs(int x,long long sm){
	if(x==n){
		ans=max(ans,sm);
	}
	if(x==1){
		sum=a[1];
	}
	for(int i=x+1;i<=n;i++){
		int bf=sum;
		sum&=a[i];
		dfs(x+1,sum);
		sum=bf;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}else if(k==2){
		int mx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[j]&a[i],mx);
			}
		}
		cout<<mx;
		return 0;
	}else if(k==n){
		int mx=a[1];
		for(int i=2;i<=n;i++){
			mx&=a[i];
		}
		cout<<mx;
		return 0;
	}else if(k==n-1){
		int mx=0,sm=0;
		for(int i=1;i<=n;i++){
			sm=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i){
					sm&=a[j];
				}
			}
			mx=max(sm,mx);
		}
		cout<<mx;
		return 0;
	}else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
