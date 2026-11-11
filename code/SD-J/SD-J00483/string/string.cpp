#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a1[200005],m1=0;
	char b1[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>b1[i];
	}
		int l=1,r=n;
	while(l<r)
	{
		if(b1[l]!=b1[r])
		{
			m1+=min(a1[l],a1[r]);
		}
		if(a1[l]>a1[r])
		{
			a1[l]-=a1[r];
			r--;	
		}
		else if(a1[l]<a1[r]){
			a1[r]-=a1[l];
			l++;
		}
		else
		{
			r--;
			l++;		
		}
		
	}
	cout<<m1;
	return 0;
}
