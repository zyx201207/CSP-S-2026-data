#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define roop(i,a,b) for(int i=b;i>=a;i--)
#define pb push_back
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,a[N];
int ma=2e9,cnt=0;
void dfs(int x,int y,int stp){
    if(x==y){
        if(stp<ma){
            ma=stp;
            cnt=1;
        }else if(stp==ma){
            cnt++;
        }
        return;
    }
    if(x>y){
        return;
    }
    loop(i,x+1,n){
        if(a[i]-a[x]<=d){
            dfs(i,y,stp+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        loop(i,1,n){
            scanf("%d",&a[i]);
        }
        if(c==11||c==12){
            long long w=a[2]-a[1];
            if(w>d)printf("0\n");
            else{
                long long ans=0;
                loop(i,1,n){
                    ans+=max(0ll,(a[n]-a[i]-d)/w-(a[n]-a[i]-d)/(d/w));
                }
                printf("%lld\n",ans);
            }
        }else if(c==13||c==14){
            long long ans=0;
            int id=1;
            loop(i,1,n){
                while(id<n&&a[id]<a[i]+d)id++;
                if(a[id]>a[i]+d)id--;
                ans+=id-i;
            }
            printf("%lld\n",ans);
        }else{
            int ans=0;
            loop(i,1,n){
                loop(j,i+1,n){
                    ma=2e9,cnt=0;
                    dfs(i,j,0);
                    if(cnt>=2)ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
