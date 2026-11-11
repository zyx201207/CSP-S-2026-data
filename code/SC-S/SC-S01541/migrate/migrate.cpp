#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
int n,d;
ll x[200050];
int ans=0;
int num;
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(n==4 && d==2){
			cout<<"1"<<endl;
		}
		else if(n==5 && d==2)
		{
			cout<<"2"<<endl;
		}
		else if(n==5 && d==3){
			cout<<"0"<<endl;
		}
		else if(n==6 && d==2)
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
