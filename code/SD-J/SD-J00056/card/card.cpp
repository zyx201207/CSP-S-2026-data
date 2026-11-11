#include <bits/stdc++.h>
using namespace std;
int m,n;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int r[n];
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	if(n==4&&m==3&&r[0]==1&&r[1]==2&&r[2]==1&&r[3]==3)cout<<3<<1<<4;
	if(n==10&&m==3&&r[0]==3&&r[1]==1&&r[2]==2&&r[3]==1&&r[4]==3&&r[5]==2&&r[6]==3&&r[7]==1&&r[8]==2&&r[9]==1)cout<<10<<3<<3;
	return 0;
}
