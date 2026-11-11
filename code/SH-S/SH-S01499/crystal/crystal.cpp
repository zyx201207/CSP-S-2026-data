#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500007; 
int n;
ll m,a[N],s[N],sum,ans;
ll scr(int x,int y){
	return a[y]*(y-x)-(s[y-1]-s[x-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int lft=1,rgt=1;
	while(rgt<=n){
		if(scr(lft,rgt)<=m){
			if(ans<rgt-lft+1) ans=rgt-lft+1;
			rgt++;
		}
		else lft++;
	}
	cout<<ans;
	return 0;
} 
