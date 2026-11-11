#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,t,n,d,x[maxn],abab[maxn],cxt;
void dfs(int a,int b,int la){
	if(a==b){
		abab[++cxt]=la;
		return;
	}
	if(a>b){
		return;
	}
	int ans=0;
	for(int i=a+1;i<=n;++i){
		if(i!=a+1&&x[i]-x[a]>d){
			break;
		}
		dfs(i,b,la+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				memset(abab,0,sizeof(abab));
				cxt=0;
				dfs(i,j,0);
				int minna=1e9,minnc=0;
				for(int k=1;k<=cxt;++k){
					if(abab[k]<minna){
						minna=abab[k];
						minnc=1;
					}else if(abab[k]==minna){
						++minnc;
					}
				}
				if(minnc==2){
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
