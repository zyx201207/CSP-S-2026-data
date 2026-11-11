#include<bits/stdc++.h>;
using namespace std;
long long n,m,ans=0;
string M[n];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>M[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		    cin>>M[m];
		    if(M[i] and M[j])
		    {
		    	ans=M[i] and M[j];
			}
			else
			{
				cout<<"0";
			}
		}
	}
	cout<<ans;
	return 0;
}
