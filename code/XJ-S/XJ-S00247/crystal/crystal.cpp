#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],maxn=0,flag=1,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++){
		if(s[i]!=s[i-1]){
			flag=0;
			break;
		}
	}
	if(flag){
		long long cnt=s[3];
		for(int i=0;;i+=cnt){
			if((m-i)<0){
				break;
			}
			m-=i,maxn++;
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long cnt=1,ti=m;
		for(int j=i-1;j>=1;j--){
			if(ti<(a[i]-a[j])){
				break;
			}
			ti-=(a[i]-a[j]);
			cnt++;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
