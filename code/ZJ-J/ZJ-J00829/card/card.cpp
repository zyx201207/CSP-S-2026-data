#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[5005];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	a[0]=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		map<int,int>mp;
		mp.clear();
		for(int i=1;i<=n;i++){
			mp[a[i]]=i;
		}
		for(int l=1;l<=m;l++){
			int ans=0;
			for(int k=1;k<=n;k++){
				if(mp[l]>=k)ans++;
			}		
			cout<<ans<<" ";
		}
	}
	else{
		for(int l=1;l<=m;l++){
			int ans=0;
			for(int k=1;k<=n;k++){
				int r=k;
				map<int,int>mp;
				mp.clear();
				for(int i=k;i<=n;i++){
					if(!mp[a[i]])mp[a[i]]=i;
					else{
						for(int j=mp[a[i]]+1;j<=i;j++)mp[a[j]]=0;
					}
				}
				if(mp[l]!=0)ans++;
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
