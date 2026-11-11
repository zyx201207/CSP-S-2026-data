//xinzizhang SH-J00685
#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000009];
int ans[2000009],neww[200009],a2[2000009],fix;
bool boo(int x)
{
	bool a=false;
	for(int i=1;i<=n;i++) {
		if(x==neww[i]) {
			
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a2[i]=a[i];
	}
	int tmp=1;
	for(int i=1;i<=n;i++)
	{
		for(int i=tmp;i<=n;i++)
		{
			neww[i-fix]=a[i];
			if(boo(a[i])){
				for(int j=i;i<=n;i++) {
				neww[i]=0;
				fix++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(boo(i)) ans[i]++;
		}
		tmp++;
		if(tmp==n) break;
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
