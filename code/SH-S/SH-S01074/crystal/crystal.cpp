#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long cr[500005];
long long p[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	bool flag2=1;
	for(int i=1;i<=n;i++){
		cin>>cr[i];
		if(cr[i]!=cr[i-1]){
			flag=0;
		}
		if(cr[i]-cr[i-1]==0){
			flag2=0;
		}
	}
	if(flag){
		cout<<n;
	}else if(flag2){
	int maxn=0;
	sort(cr+1,cr+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+(i-1)*(cr[i]-cr[i-1]);
		for(int j=i-maxn;j>=1;j--){
			if(p[i]-p[j-1]>m){
				break;
			}else{
				maxn=i-(j-1);
			}
		}
	}
	cout<<maxn;
	}else{
	int maxn=0;
	int ans=0;
	sort(cr+1,cr+n+1);
	long long unused;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+(i-1)*(cr[i]-cr[i-1]);
		for(int j=i;j>=1;j--){
			if(p[i]-p[j-1]>m){
				ans=max(1LL*ans,maxn+unused/(cr[i]-cr[j-1]));
				break;
			}else{
				maxn=i-(j-1);
				ans=max(ans,maxn);
				unused=m-p[i]+p[j-1];
			}
		}
	}
	cout<<ans;
}
	return 0;
}
