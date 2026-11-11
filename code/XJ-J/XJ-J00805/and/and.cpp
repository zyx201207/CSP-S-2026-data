#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	int maxx=x;
	int a;
	for(int i=2;i<=n;i++){
		cin>>x;
		if(x and maxx > x and m){
			maxx=x;
		}
	}
	cout<<maxx;
	return 0;
}