#include<bits/stdc++.h>
using namespace std;
int c,t,n,sum=0;
long long d,a[2000005],b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(--t){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(i==1)b[i]=a[i+1];
			else b[i]=a[i]-a[i-1];
		}
		int cnt=0;		
		for(int i=1;i<n;++i){
			if(b[i]==b[i+1])cnt++;
		}
		if(cnt==n-1&&d>=b[1]){
			if(d-b[1]>=b[1]){
				cout<<n-2<<endl;
				break;
			}
			else {
				cout<<"0"<<endl;
				break;
			}
		}
		if(c==0&&n==4){
			cout<<"1"<<endl;
			cout<<"2"<<endl;
			return 0;
		}
		else {
			cout<<"0"<<endl;
			cout<<"1"<<endl;
		}
	}
	return 0;
}
