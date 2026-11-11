#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int a1[500005]={0},f[500005]={0};
        int cnt=0;
        for(int j=i;j<=n;j++){
            a1[++cnt]=a[j];
            for(int k=1;k<cnt;k++){
                 if(a1[k]==a1[cnt]&&f[k]==0){
                    f[k+1]=1;
                    f[cnt]=2;
                 }
            }
        }
        bool e=0;
        for(int j=1;j<=cnt;j++){
            if(f[j]==1&&e==1){
                e=1;
                if(f[j+1]==2){
                    f[j+1]=1;
                    e=0;
                }else{
                    f[j+1]=1;
                }
            }
        }
        for(int j=1;j<=cnt;j++){
            if(f[j]==0)
                b[a1[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << b[i] << ' ';
    }
    return 0;
}
