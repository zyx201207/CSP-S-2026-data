#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==1)
		cout<<0;
	else if(n==2)
		if(c[1]==c[2])
			cout<<0;
		
		else
			cout<<min(a[1],a[2]);
	else{
		int l=1,r=n;
		long long ans=0;
		while(l!=r){
			if(c[l]!=c[r])
				ans+=min(a[l],a[r]);
			int x=min(a[l],a[r]);
			a[l]-=x;
			a[r]-=x;
			if(a[l]==0)
				l++;
			if(a[r]==0)
				r--;
		}
		cout<<ans;
	}	
}
