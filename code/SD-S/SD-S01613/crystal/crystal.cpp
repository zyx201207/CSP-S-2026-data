#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
int maxx(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0,l=1,num=0,c=a[1],ans=0;
	for(int i=1;i<=n;i++){
		num++;
		if(a[i]!=c){
			sum=sum+(num-1)*(a[i]-c);
			c=a[i];
		}
		while(sum>m){
			sum=sum-(c-a[l]);
			num--;
			l++;
		}
		ans=maxx(ans,num);
	}
	cout<<ans;
	return 0;
}













