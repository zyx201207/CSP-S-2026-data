#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans=0;
bool bin[maxn][30];
bool vis[maxn],flag=false;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
void getbinary(int i){
	int x=a[i],idx=0;
	while(x){
		int y=x&1;
		if(y==1)bin[i][idx]=true;
		else bin[i][idx]=false;
		idx++;
		x>>=1;
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		getbinary(i);
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!flag){
				if(bin[j][i]){
					cnt++;
				}
			} else {
				if(vis[j]&&bin[j][i]){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans+=qpow(2,i);
			if(!flag){
				flag=true;
				for(int j=1;j<=n;j++){
					if(bin[j][i]){
						vis[j]=true;
					}
				}
			} else {
				for(int j=1;j<=n;j++){
					if(vis[j]&&!bin[j][i]){
						vis[j]=false;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}