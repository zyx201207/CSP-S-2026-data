//guocaocheng aizhizhongxue SN-J00678
#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(a[n-1]==i)
		{
			cout<<n<<' ';
			continue;
		}
		else if(b[i]%2==0&&a[0]==i)
		{
			cout<<n-1<<' ';
			continue;
		}
		else if(b[i]==1&&a[0]!=i){
			cout<<1<<' ';
			continue;
		}
		
	}
	return 0;
}
