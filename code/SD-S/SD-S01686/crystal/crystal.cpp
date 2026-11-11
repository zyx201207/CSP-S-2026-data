#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
int n,cnt;
ll m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1,ff=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=0;
			break;
		}
	}
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		int dd=a[i]-a[i-1];
		if(d!=dd) ff=0;
	}
	if(f){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(m>=sum){
				cnt++;
			}else break;
		}
		cout<<cnt+1;
	}else if(ff){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=d*(i-1);
			if(m>=sum) cnt++;
			else break;
		}
		cout<<cnt;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		b[1]=0;
		for(int i=1;i<=n;i++){
			if((m-(i-1)*b[i])>=0){
				m-=b[i]*(i-1);
				cnt++;
			}else break;
		}
		cout<<cnt;
	}
	return 0;
}
