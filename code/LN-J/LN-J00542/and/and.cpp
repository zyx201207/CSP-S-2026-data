#include<bits/stdc++.h>
using namespace std;

int const N=2e5+100;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[N];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long powt[32];
    powt[1]=1;
    for(int i=2;i<=30;i++){
        powt[i]=powt[i-1]*2;
        //cout<<powt[i]<<endl;
    }
    bool siz[N][32];
    int maxx=0;
    for(int i=1;i<=n;i++){
        int a1=a[i];
        for(int j=30;j>=1;j--){
            siz[i][j]=0;
            if(a1>=powt[j]){
                siz[i][j]=1;
                a1-=powt[j];
            }
        }
    }
    long long ans=0;
    bool die[N];
    for(int i=1;i<=n;i++){
        die[i]=0;
    }
    for(int i=30;i>=1;i--){
        int an;
        an=0;
        for(int j=1;j<=n;j++){
            if(die[j]){
                //cout<<an<<endl;
                continue;
            }
            an+=siz[j][i];
            //cout<<an<<endl;
        }
        if(an<m){
            continue;
        }
        ans+=powt[i];
        for(int j=1;j<=n;j++){
            if(!siz[j][i]){
                die[j]=1;
            }
        //cout<<die[j]<<' ';
        }
        //cout<<endl;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
