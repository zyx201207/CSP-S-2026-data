#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int c,n,d,ans;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int T;
    cin>>c>>T;
    while(T--){
       cin>>n>>d;
       for(int i=0;i<n;i++){
          cin>>a[i];
       }
       for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                int jl=abs(j-i);
                if(jl%d!=0){
                    ans++;
                }
                //cout<<i<<" "<<j<<endl;
            }
       }
       cout<<ans<<endl;
       c=0,ans=0,d=0;
       for(int i=0;i<n;i++){
            a[i]=0;
       }
    }
	return 0;
}
