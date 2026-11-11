#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
const int N=2e5+10;
int n,m;
long long a[N],dp[N];
int gs(int a){
	int ans=0;
	while(a>0){
		a=a&(a-1);
		ans++;
	}
	return ans;
}
int ws(int a){
	int ans=0;
	while(a>0){
		a/=10;
		ans++;
	}
	return ans;
}
bool cmp(int a,int b){
	if(gs(a)==gs(b)){
		if(ws(a)==ws(b)){
			return a>b;
		}
		return ws(a)>ws(b);
	}
	return gs(a)>gs(b);
}
bool pd=false;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(gs(n)==1){
		pd=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				pd=false;
				break;
			}
		}
	}
	int as=a[n];
	if(pd){
		for(int i=n;i>=n-m+1;i--){
			as=as&a[i];
		}
		cout<<as;
		return 0;
	}
	/*sort(a+1,a+n+1,cmp);
	
	dp[1]=a[1];
	cout<<dp[1]<<endl;
	for(int i=2;i<=m;i++){
		cout<<a[i]<<" "<<dp[i-1]<<endl;
		dp[i]=a[i] & dp[i-1];
	}
	cout<<dp[m];*/
	return 0;
} 
