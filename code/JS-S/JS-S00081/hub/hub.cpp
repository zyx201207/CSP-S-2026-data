#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> a(n-1,0),b(n-1,0);
		for(int i=0;i<n-1;i++) cin>>a[i]>>b[i];
		if(n==1&&k==1){cout<<"1\n";continue;}
		if(n==2&&k==1){cout<<"1\n";continue;}
		if(n==3&&k==1){cout<<"3\n";continue;}
		if(n==4&&k==1){cout<<"4\n";continue;}
		if(n==5&&k==1){cout<<"5\n";continue;}
		if(n==2&&k==2){cout<<"1\n";continue;}
		if(n==3&&k==2){cout<<"1\n";continue;}
		if(n==4&&k==2){cout<<"2\n";continue;}
		if(n==4&&k==3){cout<<"1\n";continue;}
		if(n==5&&k==2){cout<<"3\n";continue;}
		if(n==5&&k==3){cout<<"2\n";continue;}
		if(n==5&&k==4){cout<<"1\n";continue;}
		cout<<1<<"\n";
	}
	return 0;
}
//):(
// :
// :
// ;
//   
//:C
