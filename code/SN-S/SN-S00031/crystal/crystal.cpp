#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
bool check(int x){
	for(int i=n;i>=x;i--){
		long long s=0,c=a[i];
		for(int j=i-1;j>=i-x+1;j--){
			s+=c-a[j];
			if(s>m)break;
		}
		if(s<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
		
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x=0;
	bool f=0;
	if(n>=2)x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			f=1;
			break;
		}
	}
	int l=0,r=n,mid;
	if(f)
	while(l<=r){
		if(l==r){
			cout<<l;
			break;
		}
		mid=(r-l)/2+l+1;
		if(check(mid)){
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	else
	{
		int s=0;
		m/=abs(x);
		for(int i=1;m>=0;i++){
			m-=i;
			s++;
		}
		if(s>n)cout<<n;
		else cout<<s;
	}
	return 0;
}
