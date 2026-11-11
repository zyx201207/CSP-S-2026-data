#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long c,t;
long long n,d;
long long a[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt;
		cin>>n>>d;
		int q;
		for(int i=1;i<=n;i++){
			cin>>a[i];

		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])%(2*d)==0){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
}
