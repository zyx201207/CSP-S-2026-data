#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,d,res,ans,minn;
int a[N];
void dfs(int x,int tar,int step){
	if(res>2) return;
	if(x==tar){
		if(step<minn){
			minn=step;
			res=1;
		}
		else if(step==minn){
			++res;
		}
		return;
	}
	for(int i=x+1;i<=tar;++i){
		if(a[i]-a[x]>d) continue;
		dfs(i,tar,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		int dd=a[2]-a[1],flag=1;
		for(int i=2;i<=n;++i){
			if(a[i]-a[i-1]!=dd){
				flag=0;
				break;
			}
		}
		if(!flag||dd<d){
			res=0;
			for(int l=1;l<=n;++l){
				for(int len=2;l+len<=n;++len){
					int r=l+len;
					res=0,minn=0x3f3f3f3f;
					dfs(l,r,0);
					if(res==2) ++ans;
				}
			}
		}else{
			ans=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}