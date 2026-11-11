#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],b[N],len,id[N],cnt[N],s[N],sum,tmp,mm;
int mx=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=a[i];
	len=unique(b+1,b+1+n)-b-1;
	if(b[1]==b[len]){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		auto it=lower_bound(b+1,b+1+len,a[i])-b;
		cnt[it]++;
		id[it]=i;
	}
	s[1]=0;
	for(int i=2;i<=len;i++){
		s[i]=s[i-1]+a[id[i]]-a[id[i-1]];
	}
	int r=upper_bound(b+1,b+1+len,a[1]+m)-b-1;
	for(int i=r;i>=1;i--){
		sum=cnt[i];
		mm=m;int num;
		for(int j=i-1;j>=1;j--){
			tmp=(s[i]-s[j]);
			num=min(mm/tmp,cnt[j]);
			if(mm>=tmp*num){
				sum+=num;
				mm-=tmp*num;
			}
			if(mm<=0)break;
		}
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
} 
