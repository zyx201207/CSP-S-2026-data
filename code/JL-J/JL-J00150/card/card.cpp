#include<bits/stdc++.h>
using namespace std;
int z_[500010],x[500010],ans[500010],to[500010],z[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int a=0;a<n;a++){
        cin>>z_[a];
    }
    for(int a=0;a<n;a++){
        copy(z_,z_+n,z);
        memset(to,-1,sizeof(to));
        memset(x,0,sizeof(x));
        for(int s=a;s<n;s++){
            x[z[s]]++;
            if(x[z[s]]<=1){
                to[z[s]]=s;
            }
            else{
                for(int d=to[z[s]];d<s;d++){
                    x[z[d]]--;
                    z[d]=-1;
                    to[z[d]]=-1;
                }
                to[z[s]]=s;
            }

        }
        for(int d=a;d<n;d++){
                if(z[d]!=-1){
                    ans[z[d]]++;
                }
            }
    }
    for(int a=1;a<=m;a++){
        cout<<ans[a]<<' ';
    }
}
