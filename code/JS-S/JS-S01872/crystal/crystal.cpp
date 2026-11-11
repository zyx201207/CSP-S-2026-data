#include <bits/stdc++.h>
using namespace std;
int n,sum;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n-i+1;j++){
            for(int k=1;k<=i;k++){
                sum+=a[j+i-2]-a[j+k-2];
            }
            if(sum<=m){
                cout<<i;
                return 0;
            }
            sum=0;
        }
    }
    return 0;
}
