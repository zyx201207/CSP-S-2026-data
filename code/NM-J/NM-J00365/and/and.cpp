#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma=0,p=0;
    long long a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
       cin>>a[i];
       if(ma<a[i]) ma=a[i];
    }
    if(m==1) cout<<ma;
    else if(m==2){
        ma=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(a[i] & a[j]>=ma) ma=a[i] & a[j];
            }
        }
        cout<<ma;
    }
    else if(m==n){
            ma=a[0];
        for(int j=1;j<n;j++){
               ma=ma & a[j];
            }
    cout<<ma;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
