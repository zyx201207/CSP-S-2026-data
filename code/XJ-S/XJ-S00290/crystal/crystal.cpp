#include<bits/stdc++.h>
using namespace std;
int c,t,ans=1;
long long n,m;
int num[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	int a;
	int b=0;
	for(int i=1;i<=t;i++){
		cin>>n;
		cin>>m;
		for(int j=1;j<=n;j++){
			cin>>num[j];
		}
		a=num[2]-num[1];
		while(m>=a){
			ans++;
			b++;
			m-=b*a;
			
			
		}
	}
	cout<<ans;
	return 0;
} 
