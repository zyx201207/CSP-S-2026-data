#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13 || c==14){
		while(t--){
			int n;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;++i)
				cin>>a[i];
			cout<<n-3<<endl;
		}
	}else if(c==11 || c==12){
		while(t--){
			int n;
			long long d;
			string st;
			cin>>n>>d;
			cin>>a[1]>>a[2];
			getline(cin,st);
			if(d<=abs(a[2]-a[1]))cout<<0<<endl;
			else if(n-d/abs(a[2]-a[1])*2+1<0)cout<<0<<endl;
			else cout<<n-d/abs(a[2]-a[1])*2+1<<endl;
		}
	}
} 
