#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e6+5;
int x[N],d,n,m=0; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	cin>>n>>d;
	while(t){
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(x[i+d+1]==x[j])	m++;
		t--;
		cout<<m;
	}
	return 0;
}
