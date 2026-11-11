#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=n;j>i+1;j--){
				if((a[j]-a[i])>d&&(a[j]-a[i])/2<=d/2){
					cnt++;
				}	
			}
			
		}
		cout<<cnt<<endl;
	}
	return 0;
}

