#include<bits/stdc++.h>
using namespace std;
long long a[500020],cnt[500020],tot;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool v[500020]={0};
            for(int ii=1;ii<=m;ii++){
                if(a[ii]==a[j])v[ii]=1;
            }
            for(int ii=1;ii<=m;ii++){
                if(!v[ii])cnt[ii]++;
            }
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i];
    }
    return 0;
}
