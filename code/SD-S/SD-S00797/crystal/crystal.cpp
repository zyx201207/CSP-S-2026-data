#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1,s=1;
	long long m,y=0;
	long a[500050]={};
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		y+=(a[i]-a[i-1])*s;
		if(y<=m){	
			s++;
			ans=max(ans,s);
		}
		else{
			while(y>m)
			{
				y-=a[i]-a[i-s];
				s--;
			}
		}
	}
	cout<<ans;
	return 0;
}
