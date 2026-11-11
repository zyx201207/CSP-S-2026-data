#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int a[10005];
 
int cnt=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	double sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	sum=(int)sum;
	int num=(int)sum;
	int t=0;//为最中间那个数的下标 
	if(n%2==0){
		t=(a[n]+1)/2;
	}else{
		t=a[n]/2;        
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
; 
	return 0;
}