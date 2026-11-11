#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n,d,a[2000006];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int mn;
        for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
                mn=INT_MAX;
				for(int k=i;k<=j;k++){
                    if(a[j]-a[k]==a[k]-a[i] && a[j]-a[k]<mn && a[k]-a[i]<mn && a[j]-a[k]<=d && a[j]-a[i]<=d){
                        cout<<a[i]<<'.'<<a[k]<<'.'<<a[j]<<'\n';
                        cnt++;
                        mn = a[k]-a[i];
                    }
				}
			}
		}
        cout<<cnt-1<<'\n';
    }

    return 0;
}
/*/

/*/
