#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx = -1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        maxx = max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    int max2 = -1;
    if(m==2){
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                max2 = max(max2,(a[i]&a[j]));
            }
        }
        cout<<max2;
        return 0;
    }
    int max3;
    if(m==n){
        max3 = a[1];
        for(int i = 1;i<=n;i++){
            max3 = (max3&a[i]);
        }
        cout<<max3;
        return 0;
    }
    return 0;
}
