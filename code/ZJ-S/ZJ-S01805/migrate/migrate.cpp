#include<bits/stdc++.h>
#define N 5010
#define ll long long
using namespace std;
int c,t,n,d;
ll a[N],to[N][N],ans;
void f(int l,int r){
	memset(to,0,sizeof to);
	for(int k=l;k<=r;k++){
		for(int i=l;i<=r;i++){
			if(k<=i)continue;
			for(int j=i+1;j<=r;j++){
				if(k>=j||i==j)continue;
				if(abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d&&abs(a[i]-a[j])>d){
					to[i][j]++;
					if(to[i][j]==2)ans++;
					if(to[i][j]==3)ans--;
				}
			}
		}
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=1;
	for(int i=1;i<=n;i++,r++){
		if(a[i+1]-a[i]>d||i==n){
			f(l,r);
			l=r+1;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
