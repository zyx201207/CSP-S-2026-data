#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=x){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}