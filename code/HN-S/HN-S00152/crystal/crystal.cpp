#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
int ans(int mid,int mm){
	int sum=0;
	for(int i=1;i<=n;i++)
		s[i]=abs(a[mid]-a[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(mm-s[i]>=0){
			sum++;
			mm-=s[i];
		}else{
			break;
		}
	}
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int mid=(1+n)/2,mid2=ceil((1+n)*1.0/2);
	cout<<max(ans(mid,m),ans(mid2,m));
	return 0;
}
