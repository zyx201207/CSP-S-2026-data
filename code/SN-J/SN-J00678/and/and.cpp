//guocaocheng aizhizhongxue SN-J00678
#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	
	for(int i=0;i<n;i++)
	{
		
		sum=a[i];
		if(i+m>n){
			break;
		}
		for(int j=i+1;j<i+m;j++)
		{
			sum=sum&a[j];		
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
