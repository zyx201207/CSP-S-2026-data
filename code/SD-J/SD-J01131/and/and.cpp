#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],ans,cnt,g=1;
bool flag=1;
void dfs(long long pos,long long ns,long long k){
	cout<<++cnt<<" "<<ns<<"\n";
	if(pos>n) return ;
	if(k==m){
		ans=max(ans,ns);
		return ;
	}
	dfs(pos+1,ns,k);
	ns=ns & a[pos];
	dfs(pos+1,ns,k+1);
	return ;
}
bool pan(long long k){
	for(int i=1;i<=31;i++){
		if(k==(pow(2,i)-1)){
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<pan(a[i])<<" ";
		if(!pan(a[i])){
			flag=0;
		}
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(flag){
		cout<<a[n-m+1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	g=(pow(2,31)-1);
//	cout<<(int)(g & 15)<<"\n";
//	cout<<g<<"\n";
	if(m==n){
		for(int i=1;i<=n;i++){
			g=g & a[i];
		}
		cout<<g;
		return 0;
	}
	dfs(1,g,0);
	cout<<ans;
	return 0;
}
