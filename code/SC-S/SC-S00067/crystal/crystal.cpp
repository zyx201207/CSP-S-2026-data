#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,cnt;
int a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
	    if(a[i]!=a[i+1]){
	    	a[i]=max(a[i+1],a[i]);
	    	a[i+1]=min(a[i+1],a[i]);
	    	cnt=abs(a[i+1]-a[i]);
	    	s[i]=a[i]+a[i+1];
		}
		else{
			a[i]=a[i]*2;
		}
		if(cnt>m)break;
	}
	if(cnt%3==0)cout<<cnt/3;
	else cout<<cnt-3;
	
} 