#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],b[MAXN],c[MAXN],d[MAXN];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(long long i=1;i<n;i++) c[i]=c[i-1]+b[n-i],d[i]=d[i-1]+c[i];
	long long re=n,l=1;
	while(re>l){
		long long mid=(l+re)/2,an;
		long long minn=d[mid-1];
		for(long long i=mid;i<n;i++) minn=min(minn,d[i]-d[i-mid+1]-c[i-mid+1]*(mid-1));
		if(m==minn) an=2;
		else if(m<minn) an=0;
		else an=1;
		if(an==1) l=mid+1;
		else if(an==0) re=mid-1;
		else{
			cout<<mid;
			return 0;
		}
	}
	cout<<l;
	return 0;
} 
//居然有差分，差分的后缀，差分的后缀的前缀，我无疑是愤怒的 