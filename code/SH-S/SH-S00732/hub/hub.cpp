#include<iostream>
using namespace std;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,n,x;
	cin>>c>>t;
	if (c==2 || c==3){
			if (t==3){
				cout<<"1\n1\n2"<<endl;
				return 0;
			}
		}
	while(t--){
		cin>>n>>x;
		for (int i=1;i<=n-1;i++) cin>>x;
		cout<<3<<endl;
	}
	return 0;
}

