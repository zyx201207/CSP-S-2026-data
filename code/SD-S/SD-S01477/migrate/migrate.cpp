#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
long long n,d,ans;
int a[N],h[N],f[N];
void dfs(int x,int fa){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(abs(a[i]-a[x])<=d&&h[x]+1<=h[i]){
				if(h[x]+1<h[i]){
					h[i]=h[x]+1;
					f[i]=1;
				}
				else f[i]++;
				q.push(i);
			}
		}
	}
}
void maind(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(h,0x3f,sizeof(h));
		memset(f,0,sizeof(f));
		h[i]=0;
		dfs(i,i);
		for(int j=1;j<=n;j++){
			if(f[j]==2){
				ans++;
			}
		}
	}
	cout<<ans/2<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>T>>T;
	while(T--){
		maind();
	}
	return 0;
}

