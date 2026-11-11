#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXX = 500005;
int a[MAXX];
//int solve[MAXX];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        num+=a[i];
    }
    cout<<num;
/*    sort(a.begin(),a.end());
    for(int i = n;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            if(a[i]%a[j]==0){
                a[i]/a[j]
            }
        }
    }
    */

    return 0;
}



