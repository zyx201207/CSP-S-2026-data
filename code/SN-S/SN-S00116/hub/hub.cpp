#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500001],m,l,r,mm=0,s=0,ans;

bool emp(int x,int y){
	return x<y;
}


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ans=-1000000000000000001;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n,emp);	

	l=1;
	r=1;
	while(r<n)
	{
		r++;
		s++;
		mm+=s*(a[r]-a[r-1]);
		while(mm>m)
		{
			mm-=a[r]-a[l];
			s--;
			l++;
			if(l>=r)
			{
				break;
			}
		}
		if(l==r)
		continue;
		ans=max(ans,s);
		
	}
	ans+=1;
	cout<<ans;
	return 0;
}



