#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
int n;
ll m;
int a[N],b[N];
//struct node{
//	int h;
//	int id;
//}b[N];
bool cmp(int x,int y){
	return x<y;
}
int r(int x){
	int ans=0,len=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			ans++;
			len++;
			b[len]=a[i];
		}
		else break;
	}
	int l=1;
	ll sum=0;
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=len;i++)
		sum+=x-b[i];
	if(sum<=m)
		return ans;
	for(int i=1;i<=len;i++){
		ans--;
		sum-=x-b[i];
		if(sum<=m)break;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m<=1000000000){
		int ans=-1;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			ans=max(ans,r(a[i]));//O( n(2*n) )250,000,000,000*1000000 24s 45pts
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		ll sum=(a[1]+a[n])*n/2;
		for(int l=n;l>=1;l--)
			for(int r=n;r>=l;r--)
				if((r-l+1)*a[r]-(a[l]+a[r])*(r-l+1)/2>=m){
					cout<<r-l+1;
					return 0;
				}
	}
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

目标：使|x-a[1]|+|x-a[2]|+|x-a[3]|+...+|x-a[n]|小于等于 m 且 a[i]的数量更多。 
*/