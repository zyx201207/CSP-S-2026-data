#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	int dy=m,de=n/m,ds=n;
	cout<<dy<<" "<<de<<" "<<ds;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
