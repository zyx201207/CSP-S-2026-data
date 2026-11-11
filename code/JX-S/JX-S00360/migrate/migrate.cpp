#include<bits/stdc++.h>
using namespace std;
int c;
int n,d,x_1t2[15],line_1t2[15],ans_1t2[15][15],way[15][15],ans_1t2d;
void dfs(int land_now,int dph){
    line_1t2[dph]=land_now;
    for(int i=0;i<dph;i++){
        if(ans_1t2[line_1t2[i]][land_now]==0||ans_1t2[line_1t2[i]][land_now]>dph-i){
            ans_1t2[line_1t2[i]][land_now]=dph-i;
            ans_1t2[land_now][line_1t2[i]]=dph-i;
            way[line_1t2[i]][land_now]=1;
            way[land_now][line_1t2[i]]=1;
        }
        else if(ans_1t2[line_1t2[i]][land_now]==dph-i){
            way[line_1t2[i]][land_now]++;
            way[land_now][line_1t2[i]]++;
        }
    }
    int _=land_now-1;
    while(x_1t2[land_now]-x_1t2[_]<=d&&_>0){
        dfs(_,dph+1);
        _--;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    if(c==1||c==2){
        int T;
        cin>>T;
        for(int qwe=0;qwe<T;qwe++){
            cin>>n>>d;
            ans_1t2d=0;
            for(int i=0;i<=n;i++){
                x_1t2[i]=0;
                for(int j=0;j<=n;j++){
                    ans_1t2[i][j]=0,way[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++) cin>>x_1t2[i];
            dfs(n,0);
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if(way[i][j]==2) ans_1t2d++;
                }
            }
            cout<<ans_1t2d/2<<endl;
        }
    }
    if(c==11||c==12||c==0){
        int T;
        cin>>T;
        for(int qwe=0;qwe<T;qwe++){
            cin>>n>>d;
            cin>>x_1t2[1]>>x_1t2[2];
            for(int i=3;i<=n;i++) cin>>x_1t2[3];
            int m_ll=d/(x_1t2[2]=x_1t2[1])+1;
            int ans=(n-m_ll*2+1)/(m_ll)*(m_ll+(n-m_ll*2+1)/(m_ll)*m_ll)/2;
            ans+=((n-m_ll*2+1)%(m_ll))*(n-m_ll*2+1)/(m_ll);
            cout<<ans;
        }
    }
    return 0;
}
