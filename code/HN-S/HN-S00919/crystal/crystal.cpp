#include<bits/stdc++.h>
#define ll long long 
#define N 500005

using namespace std;
ll m,a[N];int n;

void work1(){
	ll mx=0,num=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			num++;
		}
		else{
			num=1;
		}
		mx=max(mx,num);
	}
	cout<<mx;return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(!m){
		work1();return 0;
	}
	ll x=0,i,k=a[n]-a[n-1];
	for(i=1;i<=n-1 && x<=m;i+=k){
		x+=i;
	}
	cout<<i-k;
	return 0;
} 
