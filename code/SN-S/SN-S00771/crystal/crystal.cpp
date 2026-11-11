#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,b[500005],a[500005],cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
	}else if(n==2){
		if(a[1]+m>=a[2]){
			cout<<2;
		}else{
			cout<<1;
		}
	}else if(n==3){
		if(a[3]-a[1]<m){
			m-=a[3]-a[1];
			if(a[3]-a[2]<m){
				cout<<3;
			}
		}else if(a[3]-a[1]==m){
			cout<<2;
		}else if(a[3]-a[1]>m){
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
