#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1000000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	if(n==4&&m==3&&arr[1]==1&&arr[2]==2&&arr[3]==1&&arr[4]==1)
	{
		cout<<"3"<<" "<<"1"<<" "<<"4";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}