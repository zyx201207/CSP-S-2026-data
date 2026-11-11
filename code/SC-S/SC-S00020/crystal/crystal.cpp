#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],d[N];
int n,m;
int pos;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n%2==1)pos=(n/2)+1;
	else pos=n/2;
	for(int i=1;i<=n;i++){
		d[i]=abs(a[i]-a[pos]);
	}
	sort(d+1,d+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(m-d[i]>=0){
			m-=d[i];
			cnt++;
		}else{
			break;
		}
	}
	cout<<cnt;
}