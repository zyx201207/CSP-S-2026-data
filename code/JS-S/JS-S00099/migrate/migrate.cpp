#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,d,x[200005];
        cin >> n >> d;
        for(int i=0;i<n;i++)cin >> x[i];
        cout << n%2+d/2 << endl;
    }
}
