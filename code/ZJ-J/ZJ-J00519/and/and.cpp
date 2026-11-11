#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll n,m,a[MAXN],ans;
bool vis[MAXN],P[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(!((1<<i)&a[j])) continue;
			sum++;
		}
		if(sum>=m){
			P[i]=1;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(!((1<<i)&a[j])) vis[j]=1;
			}
		}
	}
	for(int i=0;i<=30;i++){
		//cout<<P[i];//
		if(P[i]){
			ans+=(1<<i);
		}
	}
	//cout<<"\n";//
	cout<<ans;
	return 0;
}