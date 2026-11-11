#include <bits/stdc++.h>
#define ulong unsigned long long
using namespace std;
const int N=2000006;
ulong c,ans;
ulong n,d,res,len;
long long x[N];
void dfs(int u,int v,int d){
	if(u==v){
		if(d>len) return;
		else if(d==len){
			res++;
		}else if(d<len){
			len=d;
			res=1;
		}
		return;
	}
	for(int i=u+1;i<=v;i++){
		if(abs(x[u]-x[i])<=d){
			dfs(i,v,d+1);
		}else break;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t;
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				res=0;
				len=0x3f3f3f3f;
				dfs(i,j,0);
				if(res==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
