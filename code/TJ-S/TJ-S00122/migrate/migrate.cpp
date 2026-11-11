#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e6+5;
int n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int test_id;
    cin>>test_id;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int dis=x[2]-x[1];
        if(d<=3*dis){
            cout<<0<<endl;
            continue;
        }
        int sum=0;
        for(int i=3;i<n;i++) sum+=(n-i);
        cout<<sum<<endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
