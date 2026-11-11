#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+10;
long long x[maxn];int n,mn=INT_MAX;long long d,ans,Ans;
void dfs(int b,int l,int sp){if(sp>mn) return;
	if(l==b){
		if(sp==mn) ans++;
		else mn=sp,ans=1;
		return;
	}for(int i=l+1;i<=b;i++){
		if(x[i]-x[l]>d) break;
		dfs(b,i,sp+1);
	}
}
int main(){freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;Ans=0;
		if(n<=9){f(i,1,n) cin>>x[i];
			f(i,1,n) f(j,i+1,n) ans=0,mn=INT_MAX,dfs(j,i,0),Ans+=(ans==2);
			cout<<Ans<<'\n';
		}
	} 
	return 0;
}

