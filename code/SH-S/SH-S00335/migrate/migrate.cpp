#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e6+5;

int main(){
	ios::sync_with_stdio(0);	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
    while(t--){
        cin>>n>>m;
        if(n<=3){
            cout<<"0\n";
        }
        if(c<=10||c>12){
            cout<<"0\n";
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll r=1; a[n+1]=a[n]+a[2]-a[1];
        a[n+2]=a[n]+a[2]-a[1];
        while(r<=n+1&&a[r]-a[i]<m*2){
            r++;
        }
        r--;
        cout<<n-r+1<<"\n";
    }
	return 0;
}