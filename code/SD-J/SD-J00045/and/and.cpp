#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],s[N],e[N],maxn=-1,ans=-1;
bool flag=0;
void dfs(int x,int tot,int step){
//	cout<<x<<" "<<tot<<" "<<step<<endl;
	if(x>n) return ;
	if(step==m){
		for(int i=x+1;i<=n;i++){
			long long asdfghjkl=tot&a[i];
			ans=max(ans,asdfghjkl);			
		}
		return ;
	}
	for(int i=x+1;i<=n;i++){
		int asdfghjkl=tot&a[i];
//		cout<<asdfghjkl<<endl;
		dfs(i,asdfghjkl,step+1);		
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>3) flag=1;
		maxn=max(a[i],maxn);
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]&a[i];
	}
	if(flag==0){
		int aaa=0,bbb=0,ccc=0;
		for(int i=1;i<=m;i++){
			if(a[i]==1) aaa++;
			else if(a[i]==2) bbb++;
			else if(a[i]==3) ccc++;
		}
		if(ccc>=m) cout<<3;
		else if(ccc+bbb>=m) cout<<2;
		else if(ccc+aaa>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	e[n]=a[n];
	for(int i=n-1;i>=1;i--) e[i]=e[i+1]&a[i];
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<s[n];
		return 0;
	}
	else if(m==n-1){
		long long qqq=-1;
		for(int i=2;i<n;i++) 
			qqq=max(qqq,s[i-1]&e[i+1]);
		long long tot=a[2],oto=a[n-1];
		for(int i=3;i<=n;i++) 
			tot&=a[i];
		for(int i=n-2;i>=1;i--) 
			oto&=a[i];
		cout<<max(qqq,max(tot,oto));
	}
	else {
		for(int i=1;i<=n;i++){
			dfs(i,a[i],2);
//			cout<<ans<<endl;
		}
		cout<<ans;
	}
	return 0;
}
