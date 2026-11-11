#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int ans=0;
	int a[300005];
	char b[30];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
		ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			a[r]-=a[l];
			l++;
		}
		}
		else{
			if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			a[r]-=a[l];
			l++;
		}
		}
		
	}
	cout<<ans;
	return 0;
}