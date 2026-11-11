#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=5e3+5;
int c,T;
int n,ans;
ll x[N],d;
int f[M][M],num[M][M];
void clear(){
    ans=0;
    if(n<=M-5){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                f[i][j]=(i==j?0:0x3f3f3f3f),num[i][j]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        clear();
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        ans=0;
        if(c>=1&&c<=10){
        	memset(f,0x3f,sizeof(f));
        	for(int i=1;i<=n;++i){
        		f[i][i]=0;
			}
            for(int i=2;i<=n;++i)
                for(int j=1;j<i;++j){
                    for(int k=i-1;k>=j;--k){
                        if(x[i]-x[k]<=d){
                        	if(f[j][i]==f[j][k]+1){
                                num[j][i]+=1;
                            }else if(f[j][i]>f[j][k]+1){
                                num[j][i]=1;
                                f[j][i]=f[j][k]+1;
                            }
						}else break;
                    }
                    
                    if(num[j][i]==2){
                    	ans+=1;
					}
                }
            cout<<ans<<'\n';         
        }else if(c==11||c==12){
            ll dis=x[2]-x[1];
            if(dis%d==0){
                cout<<0<<'\n';
                continue;
            }
            for(int i=1;i<=n-1;++i){
                ll cnt=1ll*dis*i/d,dx=1ll*dis*i%d;
            } 
        }
    }
    

    return 0;
}

