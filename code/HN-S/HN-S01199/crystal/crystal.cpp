#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m;
int ans=0;
int a[N];
int b[N];
int c[N];
void check(int pos){
	int k=0;
	for(int i=1;i<=n;i++){
		if(pos>=a[i]){
			b[i]=pos-a[i];
			
		}
		else{
			k=i;
			break;
		}
	}
	int num=0;
	for(int i=1;i<=k;i++){
		num+=b[i]; 
	}
	if(num<=m){
		ans=max(ans,k);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		check(a[i]);
	}
	cout<<ans-1;
	return 0;
}
