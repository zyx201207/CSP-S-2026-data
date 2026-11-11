#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500009],d[500009],cnt,res,ans;
ll r=1,add=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	res=1;
	for(int l=1;l<=n;l++){
		if(r==n)break;
		r++;
		cnt+=d[r]*res;
		add+=d[r];
		res++;
		while(cnt>m){
			cnt-=add;
			l++;
			add-=d[l];
			res--;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
