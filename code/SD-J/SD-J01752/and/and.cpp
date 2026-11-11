#include<bits/stdc++.h>
using namespace std; 
//Trick||Treat!
#define int long long
const int N=2e5+10;
int n,m,a[N],ans=0,sum=0;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=30;i>=0;i--){
		int d=(1<<i),cnt=0;
		sum=(ans|d);
		for(int j=1;j<=n;j++){
			if((a[j]&sum)==sum)cnt++;
		}
		if(cnt>=m)ans=sum;
	}
	cout<<ans;
	return 0;
//262142
}
