#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int a[400010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    for (int i=1;i<=n;i++){
        int s=a[i];
        for (int j=i;j<n;j++){
            if(j>m){
                break;
            }
            s=(s&a[j]);
        }
        if (s>=x){
            x=s;
        }
    }
    cout <<x;
    return 0;
}
