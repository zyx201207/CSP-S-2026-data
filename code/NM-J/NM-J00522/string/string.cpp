#include<bits/stdc++.h> 
using namespace std;
int a[200005];
char c[200005];
bool f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  if(c[i]==c[j]) f=true;
	if(f==true) cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
