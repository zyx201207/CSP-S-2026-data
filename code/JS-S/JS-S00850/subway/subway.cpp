#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
int c,n,m,d,q;
int a[500010],cnt1[500010],cnt2[500010][2];
vector<node>b[510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        b[i].push_back({x,y});
    }
    if(c==20&&c==21){
        while(q--){
            int x,y;
            cin>>x>>y;
            int px1=0,px2=0,py1=0,py2=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<b[i].size();j++){
                    if(i==1&&b[i][j].x==x){
                        px1=j;
                    }
                    if(i==1&&b[i][j].x==y){
                        py1=j;
                    }
                    if(i==2&&b[i][j].x==x){
                        px2=j;
                    }
                    if(i==2&&b[i][j].x==y){
                        py2=j;
                    }
                    cnt1[b[i][j].x]++;
                    cnt2[b[i][j].x][i]=j;
                }
            }
            long long ans1=1e18,ans2=1e18,ans3=1e18,ans4=1e18;
            if(px1>0&&py1>0){
                ans1=a[x]+b[1][px1].y+b[1][px2].y+a[y];
            }
            if(px2>0&&py2>0){
                ans2=a[x]+b[2][px2].y+b[2][py2].y+a[y];
            }
            if(px1>0&&py1==0&&px2==0&&py2>0){
                for(int i=1;i<=n;i++){
                    if(cnt1[i]==2){
                        ans3=min(ans3,(long  long)(b[1][cnt2[i][1]].y+b[2][cnt2[i][2]].y));
                    }
                }
                ans3+=a[x]+b[1][px1].y+b[2][py2].y+a[y];
            }
            if(px1==0&&py1>0&&px2>0&&py2==0){
                for(int i=1;i<=n;i++){
                    if(cnt1[i]==2){
                        ans4=min(ans4,(long long)(b[2][cnt2[i][2]].y+b[1][cnt2[i][1]].y));
                    }
                }
                ans4+=a[x]+b[2][px2].y+b[1][py1].y+a[y];
            }
            cout<<min({ans1,ans2,ans3,ans4})<<"\n";
        }
    }
    return 0;
}
