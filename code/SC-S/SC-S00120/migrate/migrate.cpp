#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ant=a[2]-a[1];
		if(d/ant<2){
			cout<<0<<endl;
			continue;
		}
		long long cnt=d/ant;
		cout<<(n-2*cnt+1)*(cnt-1)+((cnt-2)*(cnt-1))/2<<endl;
	}
	return 0;
}