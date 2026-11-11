#include<bits/stdc++.h>
using namespace std;
long long a[2000005],ans,d;
int n,t,c;
int find(long long x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>=x){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int j=find(a[i]+d);
			int p=find(a[j-1]+d);
			ans+=(p-j-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
