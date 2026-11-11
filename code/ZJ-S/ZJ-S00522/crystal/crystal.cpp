#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,mx;
ll m,a[N],t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2,j=1;i<=n;i++){
		t+=(a[i]-a[i-1])*(i-j);
		while(t>m){
			t-=a[i]-a[j];
			j++;
		}
		mx=max(mx,i-j+1);
	}
	cout<<mx;
	return 0;
}
