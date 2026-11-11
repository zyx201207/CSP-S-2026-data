#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const int N = 1e6+10;
int n,m,a[N],maxx,cnt,ans;
ll anss;
string s[N];
bool vis[N],viss[N],ansvis[50]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,1,sizeof vis);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],ans=(ans&a[i]),maxx=max(maxx,a[i]);
	if(n==m){ cout<<ans; return 0;}
	if(m==1){ cout<<maxx; return 0;}
	int f=maxx;
	while(f!=0){
		f/=2,cnt++;
	}
	for(int i=n;i>=1;i--){
		int x=a[i];
		while(x!=0){
			int t=x%2;
			if(t==1) s[i]+="1";
			else s[i]+="0";
			x/=2;
		}
	}
//	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++) cout<<s[i]<<endl;
	for(int i=cnt-1;i>=0;i--){
		int cntt=0;
		memset(viss,0,sizeof viss);
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			else{
				int x=int(s[j][i]-'0');
//				cout<<x<<" ";
				if(x==1) cntt++,viss[j]=1;
			}
		}
//		cout<<endl;
		if(cntt>=m){
			ansvis[i]=1;
			for(int j=1;j<=n;j++) vis[j]=viss[j];
//			for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//			cout<<endl;
		}
	}
//	for(int i=0;i<cnt;i++) cout<<ansvis[i]<<" ";
	for(int i=0;i<cnt;i++){
		if(ansvis[i]==1) anss+=pow(2,i);
	}
	cout<<anss;
	return 0;
}
