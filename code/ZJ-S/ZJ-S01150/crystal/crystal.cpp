#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=1,cnt=0,ans=0;
	for(int i=2;i<=n;i++){
		cnt+=b[i]*(i-l);
		while(l<i&&cnt>m){
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//15:11:27