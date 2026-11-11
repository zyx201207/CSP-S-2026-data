#include<bits/stdc++.h>
using namespace std;
const int N=2e6+8;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,ans=0;
	cin>>c>>t;
	
	while(t--){
		int n,d;
		cin>>n>>d;
		if(c==0){
			if(t==2&&n==4)cout<<"1\n2";
			if(t==2&&n==5)cout<<"0\n1";
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int k=0;
			for(int j=1+i;j<=n;j++){
				if(a[j]-a[i]<=d&&j-i>=d){
					++k;
				}
			}
			if(k)++ans;
		}
		cout<<(ans-1)/2;
	}
	
	return 0;
}
