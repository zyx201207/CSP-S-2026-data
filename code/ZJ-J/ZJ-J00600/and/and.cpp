#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const int maxn=2e5+5;
int n,m;
ll ans,a[maxn];
bool vis[maxn];
void f0(int now,ll temp){
	if(now==m)ans=max(ans,temp);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		f0(now+1,temp&a[i]);
		vis[i]=0;
	}
}
ll f1(){
	if(m==n){
		ans=INT_MAX;
		for(int i=1;i<=n;i++)ans&=a[i];
		return ans;
	}
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		return ans;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	return ans;
}
ll f2(){
	sort(a+1,a+1+n,[](ll A,ll B){
		return A>B;
	});
	int i=1;
	while(a[i]==3&&m>0)m--,i++;
	if(m==0)return 3;
	ll temp=m;
	while(a[i]==2&&temp>0)temp--,i++;
	if(temp==0)return 2;
	while(a[i]==1&&m>0)m--,i++;
	if(m==0)return 1;
	return 0;
}
int main(){
	FASTIO;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)flag=false;
	}
	if(n<=20){
		f0(0,INT_MAX);
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		cout<<f1();
		return 0;
	}
	if(flag){
		cout<<f2();
		return 0;
	}
	sort(a+1,a+1+n,[](ll A,ll B){
		return A>B;
	});
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
