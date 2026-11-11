#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum;
    int r[200005];
    cin >> n >> m;
    for(int i = 1;i <= n; i ++){
        cin>>r[i];
        while(m){
            sum = r[i];
            if(m == 1){
                break;
            }
            for(int j= m; j >=1; j --){
            if((r[i] & r[i+1]) >= sum){
              sum =  r[i] & r[i+1];
            }}
            m--;

    }}
    cout << sum;
    return 0;
}
