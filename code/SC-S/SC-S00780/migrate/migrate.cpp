#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3e3+10;
int n,m,c,T,a[N],d,f[N][N],num[N][N],mi[N];
vector<int> g[N];
void init(int n){
	rep(i,1,n){
	    mi[i]=INT_MAX;
		rep(j,1,n){
			f[i][j]=INT_MAX;
			num[i][j]=0;
		} 
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){	
	    cin>>n>>d;
		init(n);
		int ans=0;
		rep(i,1,n) cin>>a[i];
    	if(c==11||c==12){
    		if(a[3]-a[1]<=d) cout<<n-3<<'\n';
    		else cout<<0<<'\n';
		}else{
			rep(i,1,n){
			    f[i][i]=0;
				rep(j,i+1,n){
					if(a[j]-a[i]<=d) f[i][j]=1,num[i][j]=1;
					mi[j]=min(mi[j],i);
				}
			}
			rep(i,1,n){
				rep(j,i+1,n){
					rep(k,mi[j],j-1){
						if(f[i][j]>f[i][k]+f[k][j]){
							num[i][j]=num[i][k];
							f[i][j]=f[i][k]+f[k][j];
						}else if(f[i][j]==f[i][k]+f[k][j]){
							num[i][j]+=num[i][k];
						}
					}
				}
			}
		    rep(i,1,n){
				rep(j,i+1,n){
					//cout<<num[i][j]<<" ";
					if(num[i][j]==2) ans++;
				}//cout<<'\n';
			}cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
感觉挺板子，但是我不会啊

考虑能为 2 种类的情况不多 应该是枚举+计数

写了个很坏的dp 不知道能拿多少

反正都与我无关了

感觉今年石室中学人有点多 

我们sszx也是好起来了 雾 
*/ 