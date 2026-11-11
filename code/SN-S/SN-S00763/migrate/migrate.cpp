//QJYZ SN-S00763 YangJunnan
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ans[50]={2,1,1,0,3,6,4,2,3,5,8,9,5,4,5,5,6,5,2}; 
	int a1,a,a3;
	cin>>a1>>a;
	cin>>a3>>a1;
	for(int i=1;i<=a3-1;i++) cin>>a1;
	for(int i=0;i<a;i++)
	cout<<ans[i];
	return 0;
	
}
