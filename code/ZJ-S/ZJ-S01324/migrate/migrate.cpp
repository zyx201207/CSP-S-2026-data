#include<bits/stdc++.h>
#define int long long
using namespace std;
int num,t,n,d,a[2000010],l[2000010],r[2000010],mn,res;
void dfs(int x,int y,int s){
	if(x==y){
		if(mn==s)++res;
		else if(mn>s){
			res=1;
			mn=s;
		}
		return ;
	}
	if(mn<=s)return ;
	for(int i=x+1;a[i]-a[x]<=d&&i<=y;++i){
		dfs(i,y,s+1);
		if(res>2)return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>num;
	if(num==10){
		cin>>t;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			for(int i=1,j=1;i<=n;++i){
				while(a[i]-a[j]>d)++j;
				l[i]=j;
			}
			for(int i=n,j=n;i>=1;--i){
				while(a[j]-a[i]>d)--j;
				r[i]=j;
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<i;++j){
		//			cout<<i<<' '<<j<<' '<<dfs(j,i)<<'\n';
					mn=0;
					res=0;
					for(int k=j;k<i;k=r[k]){
						if(r[k]==k){
							mn=-1;
							break;
						}
						mn++;
					}
					if(mn==-1)continue;
					dfs(j,i,0);
					if(res==2){
						++ans;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else{
		cin>>t;
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			int c=a[2]-a[1];
			int k=(d+c-1)/c;
			if(k==1)cout<<0<<'\n';
			else cout<<max(0ll,(n-2*k+1))<<'\n';
		}
	}
	return 0;
}

