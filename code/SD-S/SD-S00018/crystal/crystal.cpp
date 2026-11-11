#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
const int N=5e5+5;
ll n,a[N],m,pre[N],prsum[N];
ll maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=5e5){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			prsum[i]=prsum[i-1]+(a[2]-a[1]);
		}
		__int128 sum=0;
		for(int i=1;i<=n;i++){
			if(sum+prsum[i]<=m){
				sum+=prsum[i];
				maxn++;
			}
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pre[1]=0;
	for(int i=2;i<=n;i++){
		pre[i]=a[i]-a[i-1];
		prsum[i]=prsum[i-1]+pre[i];
	}
	for(int r=2;r<=n;r++){
		ll sum=0;
		int l=r;
		while(sum+(prsum[r]-prsum[l-1])<=m&&l-1>0){
			l--;
			sum+=prsum[r]-prsum[l];
		}
		maxn=max(maxn,(ll)r-l+1);
	}
	cout<<maxn;
	return 0;
}

