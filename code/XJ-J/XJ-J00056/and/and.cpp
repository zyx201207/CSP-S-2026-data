#include<bits/stdc++.h>

using namespace std;
int a[2000005];
int b[2000005];
int ans,maxs=-1,ans2;
int mc=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans&=a[i];
		maxs=max(maxs,a[i]);
		b[a[i]]++;
		if(a[i]&&b[a[i]]>=2)
			ans2=a[i];
	}
	if(m==n)
		cout<<ans;
	else if(m==1)
		cout<<maxs;
	else if(m==2)
		cout<<ans2;
	else{
		sort(a,a+n);
		for(int i=0;i<n;i++){
			int cnt;
			for(int j=i;j<i+m;j++)
				cnt&=a[j];
			mc=max(mc,cnt);
		}
		cout<<mc;	
	}
	return 0;
} 
