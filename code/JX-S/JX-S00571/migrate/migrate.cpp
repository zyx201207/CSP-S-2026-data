#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,f[5005][5005],l[5005][5005],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
			long long aa;
			cin>>aa;
			a[i]=aa;
		}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=N;
                if(i==j) f[i][j]=0;
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i;j<=n;j++){
                if(a[j]-a[i]<=d){
                    f[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
				if(l[i][j]!=N) l[i][j]=1;
                else l[i][j]=0;
            }
        }
        for(int i=1;i<=n-2;i++){
            for(int k=i+1;k<=n-1;k++){
                for(int j=k+1;j<=n;j++){
                    if(f[i][k]+f[k][j]==f[i][j]){
                        l[i][j]++;
                    }
                    if(f[i][j]>f[i][k]+f[k][j]){
                        f[i][j]=f[i][k]+f[k][j];
                        l[i][j]=1;
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(l[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
