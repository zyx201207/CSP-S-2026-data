#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,a[500005];
int b[500005],s[500005],f = 1,m;
signed main(){
	
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	for(int i= 1;i<=n;i++){
		cin>>a[i];
		//b[i] = a[i]-a[i-1];
	}
	
	sort(a+1,a+n+1);
	for(int i =1;i<=n;i++){
		s[i] = s[i+1]+a[i];
	}
	int c = 1,f =2,cnt = 0;
	if(c<=f and f<=n){
		if(cnt<=m){
			cnt+=c;
		}
	}
	for(int i  =1;i<=n;i++){
		cnt = max(cnt,i-f);
	}
	cout<<cnt;
	
	
	
	
	return 0;
} 
