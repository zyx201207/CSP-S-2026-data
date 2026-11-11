#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m,x,y;
	cin>>n>>m;
	bool nbb=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(i>=3&&nbb){
			x=a[i-1]-a[i-2];
			y=a[i]-a[i-1];
			if(x!=y){
				nbb=0;
				break;
			}
		}
	}
	long long ansi=1,ans=0,cnt=1;
	if(nbb){
		x=a[2]-a[1];
		for(long long i=1;i<=n;i++){
			if(ans+x*i<=m){
				ans+=x*i;
				ansi=i;
			}
			else{
				cout<<ansi;
				return 0;
			}
		}
	}
	for(long long i=n;i>=1;i--){ 
		for(long long j=i-1;j>=1;j--){
			if(ans+a[i]-a[j]<=m) {
				ans+=a[i]-a[j];
				cnt=i-j+1;
			}
			else break;
		}
		ans=0;
		if(ansi<cnt){
			ansi=cnt;
		}
	}
	cout<<ansi;
	return 0;
} 
