#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
bool x=1;
int y;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y=a[2]-a[1];
		if(a[i]-a[i-1]!=y&&i>2){
			x=0;
		}
	}
	if(x){
		int cnt=0;
		for(int i=1;;i++){
			m-=i*abs(y);
			cnt++;
			if(m<0){
				cnt--;
				break;
			}
			if(m==0){
				break;
			}
		}
		cout<<cnt+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=m;
		for(int j=1;j<i;j++){
			b[i]++;
			cnt-=a[i]-a[j];
		}
		if(cnt<0){
			break;
		}
	}
	long long maxn=LONG_LONG_MIN;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,b[i]);
	}
	cout<<maxn;
	return 0;
}