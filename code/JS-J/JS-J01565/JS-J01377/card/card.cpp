#include<bits/stdc++.h>
using namespace std;

int ans[300010],a[500010]={0},b[500010]={0},c[500010]={0};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]==0;
            c[j]==0;
        }
        for(int j=i;j<=n;j++){
            for(int k=1;k<j;k++){
                if(b[k]==a[j]){
                    for(int ii=k;ii<=j-1;ii++){
                        b[ii]=0;
                    }
                }
            }
            b[j]=a[j];
        }
        for(int j=1;j<=n;j++){
            if(!c[a[j]]){
                ans[a[j]]++;
                c[a[j]]=1;
            }
        }
    }
    ans[a[n]]=n;
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
