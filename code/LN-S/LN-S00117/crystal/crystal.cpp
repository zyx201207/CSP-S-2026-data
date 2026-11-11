#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n=0;
long long m=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--){
        for(int j=n;j>=i;j--){
            long long sum = 0;
            for(int k=j-i+1;k<j;k++){
                sum += (a[j]-a[k]);
            }
            if(sum <= m){
                cout << i;
                return 0;
            }
        }
    }
    cout << 1;
    return 0;
}
