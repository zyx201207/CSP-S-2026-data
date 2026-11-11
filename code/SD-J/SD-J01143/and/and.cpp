#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long a[N],n,m,ans,f=1;
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int state=1;state<(1<<n);state++){
		long long sum=0,cnt=1,f=1;
		for(int i=0;i<n;i++){
			if(state&(1<<i)){
				if(f){
					f=0;
					sum=a[i+1];
				}else{
					cnt++;
					sum=(sum&a[i+1]);
					
				}
			}
		}
		if(cnt==m) ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
