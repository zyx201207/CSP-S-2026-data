#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200010];
bool cnn[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnn[i]=true;
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(cnn[j]&&(a[j]&(1<<i)))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(cnn[j]&&(a[j]&(1<<i))==0)cnn[j]=false;
			}
		}
	}
	cout<<ans;
}