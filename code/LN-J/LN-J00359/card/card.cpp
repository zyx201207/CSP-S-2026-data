#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[300010],q[500010],t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) q[j]=0;
        for(int j=i;j<=n;j++){
            t=0;
            for(int k=i;k<=j;k++){
                if(q[k]==a[j]){
                    t=k;
                    break;
                }
            }
            if(t) for(int k=t;k<=j;k++) q[k]=0;
            q[j]=a[j];
        }
        for(int j=i;j<=n;j++) s[q[j]]++;
    }
    for(int i=1;i<=m;i++) cout <<s[i]<<" ";
    return 0;
}
