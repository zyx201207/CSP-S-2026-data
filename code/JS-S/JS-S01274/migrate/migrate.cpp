#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,T;
int n;
ll d;

ll a[2000005];
int nxt[2000005];

int dis[2000005];
ll cnt[2000005];

void solve_300(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[j]=20000000;
            cnt[j]=0;
        }
        dis[i]=0;cnt[i]=1;
        queue <int> q;
        q.push(i);
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(int i=tmp+1;i<=nxt[tmp];i++){
                if(dis[i]==dis[tmp]+1)
                    cnt[i]+=cnt[tmp];
                else if(dis[i]>dis[tmp]+1){
                    cnt[i]=cnt[tmp];
                    dis[i]=dis[tmp]+1;
                    q.push(i);
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(cnt[j]==2)
                ans++;
        }
    }
    printf("%d\n",ans);
    return ;
}

void solve_A(){
    if(nxt[1]-1<=1)
        printf("0\n");
    else
        printf("%d\n",max(n-2*nxt[1]+3,0));
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T){
        T--;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int l=1,r=1;l<=n;l++){
            while(a[r+1]-a[l]<=d&&r<n) r++;
            nxt[l]=r;
        }
        //printf("%d %d\n",n,nxt[1]);
        if(n<=300){
            solve_300();
        }else if(c==11||c==12||c==0){
            solve_A();
        }else
            solve_300();
    }
    return 0;
}
