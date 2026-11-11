#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=5e5+5,MAXN2=3e5+5,INF=0x3f3f3f3f;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[MAXN]={};
    int d[MAXN][MAXN2]={};
    int fst[MAXN2]={},ifr[MAXN]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            d[i][j]=d[i+1][j]+(a[i]==j);
            if(a[i]==j){//appear
                if(fst[a[i]]!=0){//not first
                    ifr[i]=fst[a[i]];//infer
                }
                else{
                    fst[a[i]]=i;
                }
            }

        }
        if(ifr[i]){
            for(int j=1;j<=m;j++){
                d[i][j]=d[ifr[i]][j];
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<d[i][j]<<' ';
        }
        cout<<"IFR"<<ifr[i];
        cout<<endl;
    }
    for(int j=1;j<=m;j++){
        cout<<fst[j]<<' ';
    }
    cout<<endl;
    */
    for(int j=1;j<=m;j++){
        int su=0;
        for(int i=n;i>=1;i--)su+=d[i][j];
        cout<<su<<' ';
    }
}
