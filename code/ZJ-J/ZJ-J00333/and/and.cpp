#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],Max,Tmpm_n,ans;
bool f[200005];
void dfs(int x,int num){
	if(num==m){
		long long k,tmp=0;
		for(int i=1;i<=n;i++)cout<<f[i];
		cout<<"\n";
		for(int i=1;i<=n;i++){
			if(tmp==0&&f[i]==1){
				tmp=1;
				k=a[i];
			}
			if(f[i]==1){
				k&=a[i];
			}
		}
		ans=max(ans,k);
		return;
	}
	if(num<m){
		f[x]=1;
		dfs(x+1,num+1);
		f[x]=0;
	}
	dfs(x+1,num);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool tmpA=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(m==1){
		cout<<Max;
		return 0;
	}
	if(m==n){
		Tmpm_n=a[1];
		for(int i=2;i<=n;i++)Tmpm_n&=a[i];
		cout<<Tmpm_n;
		return 0;
	}
	long long Tn=n;
	while(Tn%2==0)Tn/=2;
	if(Tn==1){
		int Ans=a[n],k=1;
		for(int i=n-1;i>=1;i--){
			if(k==m)break;
			Ans&=a[i];
			k++;
		}
		cout<<Ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}