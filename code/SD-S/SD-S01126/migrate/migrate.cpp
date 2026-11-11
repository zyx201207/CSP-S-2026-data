#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
#define forg(a,b,c) for(ll g=a;g<=b;g+=c)
using namespace std;
const ll N=5e3+5;
ll c,t,n,d,a[N],sum[N],f[N][N],p[N][N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			fori(1,n,1)scanf("%lld",&a[i]);
			if(n<=3){printf("0\n");continue;}
			ll mi=a[2]-a[1];ll m=d/mi;
			if(m<=1||2*m>n){printf("0\n");continue;}
			printf("%lld\n",n-2*m+1);
		}
	}
	else if(c>=15&&c<=18){
		while(t--){
			scanf("%lld%lld",&n,&d);
			fori(1,n,1)scanf("%lld",&a[i]);
			ll pe;
			fori(1,n,1){
				ll flag=1;
				forj(1,n,1){
					if(abs(a[i]-a[j])>d){flag=0;break;}
				}
				if(flag){pe=i;break;}
			}
			ll le=pe-1,ri=n-pe;
			if(a[pe+1]-a[pe-1]>d)printf("0\n");
			else{
				ll cnt=0;
				for(ll i=le;i>1;i--){
					forj(ri,n,1){
						if(a[j]-a[i]>d&&a[j]-a[le]<=d&&a[j]-a[le-1]>d&&a[ri]-a[i]>d)cnt++;
					}
				}
				printf("%lld\n",cnt);
			}
		}
	}
	else{
		while(t--){
			scanf("%lld%lld",&n,&d);ans=0;
			fori(1,n,1){forj(1,n,1){p[i][j]=N;f[i][j]=0;}}
			fori(1,n,1){scanf("%lld",&a[i]);}
			fori(1,n-1,1){
				forj(i+1,n,1){
					ll l=a[j]-a[i];
					if(l>d)break;
					f[i][j]=1;
					p[i][j]=1;
				}
			}
			forg(2,n-1,1){
				fori(1,g-1,1){
					if(a[g]-a[i]>d)continue;
					forj(g+1,n,1){
						if(a[j]-a[g]>d)continue;
						if(p[i][g]+p[g][j]==p[i][j])f[i][j]++;
						if(p[i][g]+p[g][j]<p[i][j]){p[i][j]=p[i][g]+p[g][j];f[i][j]=1;}
					}
				}
			}
			fori(1,n-3,1){
				forj(i+3,n,1){
					if(f[i][j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
