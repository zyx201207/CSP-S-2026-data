#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=-1e9;
int kkk(int a,int b){
	int res=0,base=1;
	while(a||b){
		if((a%2==1)&&(b%2==1)){
			res+=base;
		}
		a>>=1;
		b>>=1;
		base<<=1;
	}
	return res;
}
bool A(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int base=1;
		for(int j=1;j<=32;j++){
			if(a[i]==base-1){
				cnt++;
				break;
			}
			base<<=1;
		}
	}
	return cnt==n?true:false;
}
void dfs(int i,int sum,int l){
	if(l==m){
			ans=max(sum,ans);
	}
	if(i>n){
		return ;
	}
	dfs(i+1,sum,l);
	dfs(i+1,sum==0?a[i]:kkk(sum,a[i]),l+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=30){
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	else if(n<=2000&&m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=2000&&m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=kkk(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,kkk(a[i],a[j]));
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(A()){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=kkk(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}