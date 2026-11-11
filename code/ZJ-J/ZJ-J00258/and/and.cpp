#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
ll a[N],num[N],ans,n,m;
void dfs(int id,int x){
	if(id==n+1||x==m+1){
		if(x==m+1){ 
			ll sum=num[1];
			for(int i=2;i<=m;i++){
				sum&=num[i];
			}ans=max(ans,1ll*sum);
		}return;
	}else{
		num[x]=a[id];
		dfs(id+1,x+1);
		num[x]=0;
		dfs(id+1,x);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool A=1,C=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		double x=log(a[i]+1)/log(2);
		if((ll)(x)!=x) A=0;
		if(a[i]>=4) C=0;
	}
	if(n<=20){
		dfs(1,1);
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(a[i]&a[j],ans);
			}
		}cout<<ans;
	}else if(A){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}else if(C){
		sort(a+1,a+1+n);
		int l=1,r=n,id;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[mid]<3){
				id=mid;
				l=mid+1;
			}else r=mid-1;
		}
		int three=n-id;
		int end=id;
		l=1,r=n;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[mid]<2){
				id=mid;
				l=mid+1;
			}else r=mid-1;
		}
		int two=end-id;
		end=id;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[mid]<1){
				id=mid;
				l=mid+1;
			}else r=mid-1;
		}
		int one=end-id;
		int zero=n-one-two-three;
		if(m<=three) ans=3;
		else{
			m-=three;
			if(m<=two){
				ans=2;
			}
			else{
				if(m<=one) ans=1;
				else ans=0;
			}
			cout<<ans;
		}
	}else if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		ll Ans=0;
		for(int i=1;i<=n;i++){
			Ans=max(ans+a[i]^ans,Ans);
		}cout<<Ans;
	}else cout<<0;
	return 0;
}
