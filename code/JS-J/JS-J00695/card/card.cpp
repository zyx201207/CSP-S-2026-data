#include<bits/stdc++.h>
using namespace std;
int n,m,v[300005],ans[300005],a[500005],b[500005];
bool v_[300005];
int main(){
    freopen("card.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        for(int i=1;i<=300001;i++){
            v_[i]=1;
        }
        for(int i=t;i<=n;i++){
            b[i]=a[i];
            for(int j=t;j<i;j++){
                if(b[j]==b[i]){
                    for(int k=j;k<i;k++){
                        b[k]=0;
                    }
                    break;
                }
            }
        }
        for(int i=t;i<=n;i++){
            if(v_[b[i]]){
                v_[b[i]]=0;
                v[b[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' ';
    }
    freopen("card.out","w",stdout);
    return 0;
}

