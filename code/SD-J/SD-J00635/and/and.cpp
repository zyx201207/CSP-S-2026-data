#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*2*1e5;
ll sqsq=1,n,m,a[N],ans,b[N];
//and:& 同1为1，其他为零 
void dfs(ll dq,ll yxgs,ll dqz){
	if(dq==n+1){
	//	cout<<yxgs<<" "<<dqz<<endl;
		if(yxgs==m){
			ans=max(dqz,ans);
		}
		return;
	}
	dfs(dq+1,yxgs,dqz);
	dfs(dq+1,yxgs+1,(dqz&a[dq]));
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
//	cout<<(1&1);
//	cout<<(1&0);
//	cout<<(0&1);
//	cout<<(0&0);
	cin>>n>>m;
	for(ll i=1;i<=31;i++){
		sqsq*=2;
		b[i]=sqsq-1;
	}
	bool flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ll flagls=0;
		for(ll j=1;j<=31;j++){
			if(a[i]==b[j]){
				flagls=1;
			}
		}
		if(flagls==0){
			flag=0;
		}
	}
	sqsq-=1;
	ans=-sqsq;	
	if(n<=20){
		dfs(1,0,sqsq);
		cout<<ans;
		return 0; 
	}
	if(m==1){
		ll big=-sqsq;
		for(ll i=1;i<=n;i++){
			big=max(big,a[i]); 
		}
		cout<<big;
		return 0; 
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(a[i]&a[j]));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=sqsq;
		for(ll i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(flag){
		ans=sqsq;
		sort(a+1,a+1+n);
		for(ll i=n;i>=m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	cout<<sqsq;
	return 0;
}
