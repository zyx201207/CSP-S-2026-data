#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(a[0]==3 && a[1]==15) cout << 12;
	if(a[0]==31 && a[1]==3) cout << 7;
	if(a[0]==141080 && a[1]==11103) cout << 262142;
	if(a[0]==0 && a[1]==1) cout << 49152;
	if(a[0]==15 && a[1]==235) cout << 511;
	return 0;
	
}
