#include<bits/stdc++.h>
using namespace std;
struct node{
	int subway_num,subway_sation,time;
};
vector<vector<int>> a;
queue<node> q;
int n,m,a,b,c,d,e,f,ans;
int a1[100055],b1[155555],c1[15555],d1[5],d2[5]
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int r;
	cin>>r>>a>>b>>c>>d;
	for (int i=1;i<=b;i++)
	{
		cin>>a[i];
	 } 
	 for (int i=1;i<=a+b;i++)
	 {
	 	cin>>b[i]; 
	 	ans+=b[i];
	 }
	 for (int i=1;i<=a+b;i++)
	 {
	 	cin>>c[i]; 
	 	ans+=c[i];
	 }
	 cout<<ans;
	return 0; 
} 
