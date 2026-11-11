#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+7;
int n,m;
long long a[MAXN];
int vis[MAXN];
int ans[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxi=0;
	for(int i=40;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)&1))cnt++;
		}
		if(cnt>=m){
			maxi=i-1;
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1)vis[j]=1;
			}
			break;
		}
	}
	for(int i=maxi;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]!=0 and ((a[j]>>i)&1))cnt++;
		}
		if(cnt>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if(vis[j]!=0 and ((a[j]>>i)&1))vis[j]=1;
				else vis[j]=0;
			}
		}
	}
	long long p=1;
	long long anss=0;
	for(int i=0;i<=40;i++){
		if(ans[i])anss+=p;
		p*=2;
		p=min(5000000000ll,p);
	}
	cout<<anss;
	
	return 0;
}
