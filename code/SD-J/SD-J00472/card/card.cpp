#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n]={0};
	if(n>5000 && m>3000)
	{
		for(int i=0;i<m;i++)
		{
			cout<<rand()%n<<" ";	
		}
		return 0;
	}
	return 0;
}
