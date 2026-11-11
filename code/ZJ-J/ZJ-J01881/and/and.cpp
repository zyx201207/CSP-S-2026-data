#include<bits/stdc++.h>
#define int long long
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;
int a[200005],ivs[200005];
int xn(int x,int w){
	return (x>>(32-w))%2;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=32;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(xn(a[j],i)==1&&ivs[j]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=1<<(32-i);
			for(int j=1;j<=n;j++){
				if(xn(a[j],i)==0){
					ivs[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}