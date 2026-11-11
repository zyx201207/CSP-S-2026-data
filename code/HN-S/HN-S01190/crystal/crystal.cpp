#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,mid,ma,s[500010];
bool check(int x,int y){
	return (a[y]*(y-x))-(s[y-1]-s[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=a[i]+s[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i))r=mid-1;
			else l=mid+1;
		}
		ma=max(i-l+1,ma);
	}
	cout << ma;
	return 0;
}

