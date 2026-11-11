#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt=0,mid,c[500005];
bool flag=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=0;
		}
	}
	if(flag){
		
	}
	mid=n/2+1;
//	cout<<mid;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=abs(a[i]-a[mid]);
	}
	sort(c+1,c+mid+1);
//	for(int i=1;i<=n;i++){
//		if(c[i]!=0){
//			cout<<c[i]<<" ";
//		}
//	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			cnt++;
		}
	}
	for(int i=1;i<=mid;i++){
		if((c[i]!=0)&&(m>=c[i])){
			m-=c[i];
			cnt++;
		}
		else if(m<c[i]){ 
			break;
		}
	}
	cout<<cnt;
	return 0;
}

