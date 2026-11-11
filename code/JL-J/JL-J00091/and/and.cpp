#include<bits/stdc++.h>
using namespace std;
long long ma=INT_MIN;
int n,m,a[120000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1) cout<<a[1];
    else if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]&a[j]>ma){
                    ma=a[i]&a[j];
                }
            }
        }
        cout<<ma;
    }else if(m==3){
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int z=j+1;z<=n;z++){
                    if(a[i]&a[j]>ma){
                        ma=a[i]&a[j]&a[z];
                    }
                }
            }
        }
        cout<<ma;
    }else{
        long long s=a[1]&a[2];
        cout<<s;
    }
    return 0;
}
