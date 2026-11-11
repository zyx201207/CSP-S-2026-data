#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q;
int w[1000000];
vector<vector<int>>a,t;
vector<vector<int>>st;
vector<vector<int>>stt;
int mi[500][500];

void gm(int& old,int ne){
    if(old>ne)old=ne;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            mi[i][j]=100000000000000LL;
            if(i==j)mi[i][j]=0;
        }
    }
    a=vector<vector<int>>(500);
    t=vector<vector<int>>(500);
    cin>>c>>n>>m>>d>>q;
    st=vector<vector<int>>(m);
    stt=vector<vector<int>>(m);
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a1,t1;
            cin>>a1>>t1;
            a[i].push_back(a1-1);
            t[i].push_back(t1);
            st[a1-1].push_back(i);
            stt[a1-1].push_back(t1);
        }
    }
    for(int i=0;i<n;i++){
        for(int s=0;s<a[i].size();s++){
            int stn=a[i][s];
            for(int b=0;b<st[stn].size();b++){
                gm(mi[st[stn][b]][i],t[i][s]+stt[stn][b]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gm(mi[i][j],mi[j][i]);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mi[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                gm(mi[i][j],mi[i][k]+mi[k][j]);
            }
        }
    }

    for(int tt=0;tt<q;tt++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        int minl=100000000000000LL;
        for(int i=0;i<st[x].size();i++){
            for(int j=0;j<st[y].size();j++){
                gm(minl,mi[st[x][i]][st[y][j]]+stt[x][i]+stt[y][j]);
            }
        }
        cout<<minl+w[x]+w[y]<<'\n';
    }

    return 0;
}