#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l[n];
	for(int i=0;i<n;i++)
		cin>>l[i];
	sort(l,l+n);
	cout<<l[n-m]; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
