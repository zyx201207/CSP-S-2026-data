#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1000;
int n,m;
int a[N];
int ans;
int k;
bool flaga=1,flagb=1;
bool check(int mid){
	int tmp=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid) break; 
		tmp+=(mid-a[i]);
		sum++;
	}
	if(tmp<=m){
		ans=sum;
		return false;
	}else{
		return true;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flaga=0;
		if(i>=3){
			k=a[2]-a[1];
			if((a[i]-a[i-1])!=k) flagb=0;
		}
	}
	if(flaga){
		for(int i=1;i<=n;i++){
			int mm=(i*i-i)/2;
			if(mm>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	if(flagb){
		for(int i=1;i<=n;i++){
			int mm=(i*i*k-i*k)/2;
			if(mm>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	int l=0,r=1e12+100;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2
kan t2

*/




