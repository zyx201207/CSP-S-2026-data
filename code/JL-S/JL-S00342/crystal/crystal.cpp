#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	int n,x,m;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>m;
		if(x==n){
			x++;
			m+=x;
		}
			
		cout<<x;
		return 0;
	}
}


