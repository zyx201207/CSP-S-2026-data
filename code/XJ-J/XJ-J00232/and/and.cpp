#include <string>
#include <iostream>
using namespace std;
int s[100],a[100];
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i] and s[i+1];
	}
	int ans =0;
	for(int i=1;i<=n;i++){
	
		if(a[i]>ans)
		{
			ans=a[i];
		}
	}
	cout<<ans;
    
}
