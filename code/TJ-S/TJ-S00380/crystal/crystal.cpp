#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 500005;

ll a[N],n,m,ans,sum[N],diff, b[N];
bool flag1=1,flag2=1;

void init(){
	b[1] = 0;
	for(int i=2;i<=n;i++){
		b[i] = b[i-1]+(i-1);
	}
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
		if(i==2){
			diff = a[2]-a[1];
		}
		if(i>2&&a[i]-a[i-1]!=diff){
			flag2=0;
		}
		if(a[i]!=i){
			flag1=0;
		}
	}
	init();
	if(flag1){
		for(int i=n;i>=1;i--){
			if(b[i]<=m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	
	else if(flag2){
		for(int i=n;i>=1;i--){
			if((b[i]*diff)<=m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	
	ll cur=0,i = n/2,j;
	
	for(j=i;j>=1;j--){
		cur = (j-1)*a[j]-sum[j-1];
		
		if(cur<=m){
			break;
		}
		cout<<j<<" "<<cur<<endl;
	}
	
	ans = max(ans,j);
	
	if(j==i){
		for(j=i;j<=n;j++){
			cur = (j-1)*a[j]-sum[j-1];
			if(cur>m){
				break;
			}
			cout<<j<<" "<<cur<<endl;
		}
		ans = max(ans,j-1);
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
/*
5 8
-3 -1 2 2 7

4


5 5
1 2 4 8 9

3
*/
