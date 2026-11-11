#include<bits/stdc++.h>
using namespace std;
//priority_queue
//operator
long long C,T,n,d;
const long long N=2e6+10;
long long a[N];
int l,r;
int ans=0x3f3f3f3f,ci;
void dfs(int now,int c){
    if(now==r+1){
        if(c<ans){
            ans=c;
            ci++;
        }else if(c==ans){
            ci++;
        }
        return;
    }
    if(c>ans) return;
    for(int i=now-1;i>=1;i--){
        if(a[now]-a[i]>d) break;
        dfs(i+1,c+1);
    }
    for(int i=now+1;i<=r;i++){
        if(a[i]-a[now]>d) break;
        dfs(i+1,c+1);
    }
    return;
}
void work(){
    ans=0x3f3f3f3f;
    ci=0;
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }

        if(C==13||C==14){
                int l=1,r=2,num=0;
            while(r<=n){
                    if(l==r) r++;
                if(a[r]-a[l]==d){
                    num++;l++;r++;
                }else if(a[r]-a[l]<d){
                    r++;
                }else{
                    l++;
                }
            }
            cout<<n*(n-1)/2-num;
            return;

        }
        int anss=0;
        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){
                l=i;r=j;
                dfs(i,0);
                if(ci==2){
                    anss++;
                }
            }
        }
        cout<<ans<<'\n';

        return ;
}
int main(){
    ios::sync_with_stdio(0);
   cin.tie(0);
    //2
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        work();
    }

    return 0;
}
