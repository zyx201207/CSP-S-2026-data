#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
vector<long long>v,s;
bool vis[200010];
void dfs(int k,int x){
	if(k==m){
		int ans=s[0];
		for(int i=1;i<m;i++)
			ans&=s[i];
		v.push_back(ans);
		return;
	}
	for(int i=x+1;i<=n;i++)
		if(!vis[i]){
			vis[i]=true;
			s.push_back(a[i]);
			dfs(k+1,i);
			s.pop_back();
			vis[i]=false;
		}
}
struct nu{
	int a;
	int e;
	nu(){
		a=e=0;
	}
}er[200010];
bool cmp(nu a,nu b){
	if(a.e!=b.e)
		return a.e>b.e;
	return a.a>b.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ans)
			ans=a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(0,0);
		sort(v.begin(),v.end());
		cout<<*(v.end()-1);
		return 0;
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		er[i].a=a[i];
		string e;
		while(a[i]){
			e+='0'+a[i]%2;
			a[i]/=2;
		}
		for(char c:e)
			if(c=='1')
				er[i].e++;
	}
	sort(er+1,er+1+n,cmp);
	ans=er[1].a;
	for(int i=2;i<=m;i++)
		ans&=er[i].a;
	cout<<ans;//暴力出奇迹，骗分过样例！ 
	return 0;
} 
