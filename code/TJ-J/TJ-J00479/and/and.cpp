#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5,M=2e30-1;
ll n,m,mx;
ll a[N];
void dfs(ll sum,ll num,ll lm){
	if(num>n or lm==0){
		if(lm==0 and num!=M)mx=max(mx,sum);
		return;
	}
	dfs(sum&a[num],num+1,lm-1);
	dfs(sum,num+1,lm);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int mx=0,x;
		for(int i=1;i<=n;i++){
			cin>>x;
			mx=max(mx,x); 
		}return cout<<mx,0;
	}if(m==n){
		int ans,x;
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>x;
			ans&=x;
		}return cout<<ans,0;
	}else {
		bool A=0,B=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(A==0){
				ll num;
				for(int j=30;j>=1;j--){
					if((1<<j)<a[j]){
						num=1<<(j+1);
						break;
					}
				}if(num-1!=a[i])A=1;
			}if(B==0 and a[i]!=i-1)B=1;
		}
		if(A==0){
			return cout<<*max_element(a+1,a+1+n),0;
		}
		dfs(M,1,m);
	}cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
