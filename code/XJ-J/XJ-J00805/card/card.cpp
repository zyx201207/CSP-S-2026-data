#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<+n;i++){
		int x;
		cin>>x;
		if(x>=1 && x<=m){
			ans+=x;
		}
		if(x==2){
			ans=0;
		}
	}
	cout<<ans;
	return 0;
}