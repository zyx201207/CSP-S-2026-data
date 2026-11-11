#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i=(s);i<=(e);i++)
#define per(i,s,e) for(int i=(s);i>=(e);i--)
typedef long long ll;
const int N=2e6+5;
ll a[N],to[N];
void work(){
    ll n,d;
    cin>>n>>d;
    rep(i,1,n){
        cin>>a[i];
        //cerr<<a[i]<<'\n';
    }
    ll _to=n;
    to[n]=n;
    per(i,n-1,1){
    	if(a[i+1]-a[i]>d){
    		_to=i;
		}
		to[i]=_to;
	}
    ll ans=0,l,r,rb,from;
    rep(i,1,n-1){
        r=l=i+1;rb=i+1,from=to[i]+1;
        rep(j,i,n){
            if(a[j]>=a[i]+d){
            	while(a[j]==a[j+1]){
            		j++;
				}
                r=j;
                break;
            }
        }
        rb=r;
        rep(j,min(l+1,n),to[i]){
            if(a[j]>=a[l]+d){
            	while(a[j]==a[j+1]){
            		j++;
				}
                rb=j;
                break;
            }
        }
        rep(j,min(r+1,n),to[i]){
            if(a[j]>a[r]+d){
            	while(a[j]==a[j+1]){
            		j++;
				}
                from=j;
                break;
            }
        }
//        fprintf(stderr,"i=%lld,ans=%lld,l=%lld,r=%lld,from=%lld,rb=%lld,to=%lld\n"
//		,i,ans,l,r,from,rb,to[i]);
        if(r-l==1){
//        	rep(j,r+1,rb){
//        		fprintf(stderr,"(u,v)=(%lld,%lld)\n",i,j);
//			}
//			rep(j,from+1,to[i]){
//        		fprintf(stderr,"(u,v)=(%lld,%lld)\n",i,j);
//			}
        	ans+=max((rb-r),0ll)+max((to[i]-from+1),0ll);
        	//fprintf(stderr,"ans=%lld\n",ans);
		}
        

    }
    cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        work();
    }
    return 0;
}
