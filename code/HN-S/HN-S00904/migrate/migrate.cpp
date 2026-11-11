#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,g=0;
	vector<int> x;
	int gi[100000];
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++){
			int xi;
			cin>>xi;
			x.push_back(xi);
		}
		double s=n;
		gi[i]=round(s/2)-1;
	}
	for(int i=0;i<t;i++){
		cout<<gi[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
