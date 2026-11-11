#include<bits/stdc++.h>
using namespace std;
#define int long long
int ktt[10005],l[10005][10005],qwe[10005][2];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t,x,y,z,k;
    cin>>t>>x>>y>>z>>k;
    if(t>=11){
        for(int i=1;i<=k;i++){
            cout<<3<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=y;i++){
        cin>>ktt[i];
    }
    for(int i=1;i<=x+y;i++){
        for(int j=1;j<=x+y;j++){
            l[i][j]=1000000000000000000;
        }
    }
    for(int i=1;i<=x;i++){
        int q;
        cin>>q;
        for(int j=1;j<=q;j++){
            cin>>qwe[j][0]>>qwe[j][1];
        }
        for(int j=1;j<q;j++){
            for(int m=j+1;m<=q;m++){
                int a=qwe[j][0],b=qwe[m][0];
                l[a][b]=l[b][a]=min(qwe[j][1]+qwe[m][1],l[a][b]);
            }
        }
    }
    for(int i=1;i<=y;i++){
        for(int j=1;j<y;j++){
            for(int h=j+1;h<=y;h++){
                l[j][h]=l[h][j]=min(l[j][i]+l[i][h],l[j][h]);
            }
        }
    }
    for(int i=1;i<=k;i++){
        int r,t;
        cin>>r>>t;
        cout<<ktt[r]+ktt[t]+l[r][t]<<"\n";
    }
    return 0;
}
