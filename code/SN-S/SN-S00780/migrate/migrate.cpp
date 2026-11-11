#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("magrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	 	for(int i=0;i<t;i++)
	 	{
	 		long long n,d,a1,a2,no;
	 		cin>>n>>d>>a1>>a2;
	 		for(int i=0;i<n-2;i++)
	 		cin>>no;
	 		if((a2-a1)>d)
	 		cout<<0<<endl;
	 		else
	 		cout<<n-3<<endl;
		 }
	}
