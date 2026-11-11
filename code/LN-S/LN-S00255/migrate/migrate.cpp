#include <bits/stdc++.h>
using namespace std;
int c,t,cnt=0;
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int x[n+1];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<cnt<<'\n';
        cnt++;
    }
    return 0;
}
