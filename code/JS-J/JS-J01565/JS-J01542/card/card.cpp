#include <bits/stdc++.h>
using namespace std;
int a[10000001],t[10000001],s[10000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int r=0;
        for(int j=i;j<=n;j++){
            int l=1;
            for(int z=1;z<=r;z++){
                if(t[z]==a[j]){
                    l=0;
                    r=z;
                    break;
                }
            }
            if(l==1){
                r++;
                t[r]=a[j];

            }
        }
        for(int i=1;i<=r;i++){
            s[t[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
