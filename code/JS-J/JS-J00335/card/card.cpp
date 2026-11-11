#include <bits/stdc++.h>
using namespace std;
int n,m,l=1;
int a[500010];
int b[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        l=i;
        while(l<=n){
            for(int i=l+1;i<=n;i++){
                if(a[l]==a[i]){
                    l=i;
                }
            }
            b[a[l]]++;
            l++;
        }
    }
    for(int i=1;i<m;i++){
        cout<<b[i]<<" ";
    }
    cout<<b[m]<<endl;
    return 0;
}
