#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tiao cout<<"Rikki_official"<<'\n'
const int N=2e6+100;
ll a[N],ans=0,cnt;
int c,t,n;
ll d;
inline int find_num(int dx,int dy){
    int x=0,juli=0;
        while(dy>dx){
            juli=0;
            while(juli<d){
                if(a[dx+1]-a[dx]>d)return 0;
                if(juli+a[dx+1]-a[dx]<=d){
                juli+=(a[dx+1]-a[dx]);
                dx++;
            }else{
                break;
            }
            if(dx==dy)return x+1;
        }
        ++x;
}
    return x;}
inline void dfs(int dx,int dy,int num,int jishu){
    if(dx==dy&&jishu==num){
        cnt+=1;
        return;
    }
    for(int i=dx+1;i<dy;i++){
        if(a[i]-a[dx]<=d)dfs(i,dy,num,jishu+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int ii=1;ii<=t;ii++){
        cin>>n>>d;
        if(n<=3){
            cout<<0<<'\n';
        }else{
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=3;i<n;i++){
                for(int j=1;j<=n-i;j++){
                    cnt=0;
                    if(a[j+i]-a[j]<=d)continue;
                    int num=find_num(j,j+i);
                    if(num==0){
                        continue;
                    }
                    dfs(j,j+i,num,0);
                    if(cnt>=2)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
