#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n; 
long long m,a[N],s[N];
bool check(int len){
	for(int i=1;i<=n-len+1;i++){
		if(a[i+len-1]*len-(s[i+len-1]-s[i-1])<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
