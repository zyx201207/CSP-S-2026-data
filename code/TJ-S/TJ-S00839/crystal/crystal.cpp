#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long n,m;
bool f1=1;
long long c=0;
long long ch(long long sum){
	int ans=0,idx=1;
	for(int i=1;ans<=sum;i++){
		ans+=i;
		idx++;
	}
	return idx-1;
}
void solve(){
	long long sum=m/c;
	cout<<ch(sum);
}
void solve1(){
	int len=1;
	int maxlen=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=s[i-1]*len;
		if(sum>m){
			maxlen=max(maxlen,len);
			len=1;
			sum=0;
			i--;
		}else{
			len++;
			
		}
	}
	cout<<maxlen;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i+1]-a[i];
		if(i>2&&f1&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f1=0;
		}else c=a[i]-a[i-1];
	}
	if(f1){
		solve();
	}else{
		solve1();
	}
	return 0;
}
