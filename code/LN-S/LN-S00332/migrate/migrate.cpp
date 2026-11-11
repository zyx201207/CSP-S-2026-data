#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        int a[n],ans=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << a[n-1]-a[0] << endl;
    }
    return 0;
}
