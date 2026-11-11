#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int j=i+3;
			if(j>n)break;
			if(a[j-1]-a[i]<=d && a[j]-a[i+1]<=d && a[j]-a[i]>d){
				cnt+=1;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}