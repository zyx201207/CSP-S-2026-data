#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,d,sum,cnt;
int a[N];
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]+2*d-1>n)break;
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])%d==d-1&&a[j]-a[i]>=2*d-1){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
    return 0;
}
