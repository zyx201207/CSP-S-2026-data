#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dis[200005],p[35],mp[35],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=29;i++){
		p[i]=p[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dis[i]=32;
	}
	for(int i=29;i>=0;i--){
		int num=0,idx;
		for(int j=1;j<=n;j++){
			if(mp[dis[j]]==1) continue;
			idx=a[j]&p[i];
			if(idx) num++;
			else dis[j]=i;
		}
		if(num>=m){
			mp[i]=1;
			ans+=p[i];
		}
	}
	cout<<ans;
	return 0;
}
