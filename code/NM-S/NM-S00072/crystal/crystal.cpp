#include<bits/stdc++.h>
using namespace std;
bool vis[500010];
long long a[500010];
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(vis,0,sizeof(vis));
	int n;
	long long m;
	cin>>n>>m;
	map<int ,int> mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}	
	a[0]=0x3f3f3f3f;
	a[n+1]=0x3f3f3f3f;
	sort(a+1,a+n+1);
	int ans=-112;
	for(int i=1;i<=n;i++){
		int r=i,l=i;
		int hm=m; 
		int na=1;
		
		while(hm>0||(r<=0&&l>=n)){
			int nl=abs(a[l+1]-a[i]);
			int nr=abs(a[r-1]-a[i]);
			if(nr<nl){
				//cout<<r<<"L ";
				r--;
			}
			else{
				//cout<<l<<"R ";
				l++;
			}
			hm-=min(nl,nr);
			na++;
		}
		//cout<<endl<<na;
		if(hm<0)na--;
		ans=max(na,ans);
		//cout<<endl<<hm<<" ";
		//cout<<na<<endl<<"--------------------------"<<endl;
	}
	cout<<endl;
	cout<<ans;
	return 0;
}
