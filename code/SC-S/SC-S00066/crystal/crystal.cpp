#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll arr[N],pre[N];
ll n,m,ans;
ll del;
bool is;

bool cmp(ll x,ll y) {return x>y;}

void work(){
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+arr[1]-arr[i];
	}
	
//	cout<<"初始pre:";
//	for(int i=1;i<=n;i++) cout<<pre[i]<<' ';
//	cout<<'\n';
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pre[j]=pre[j-1]+arr[i]-arr[j];
			if(i==j) pre[j]=0;
		}
		
//		cout<<"当前pre:";
//		for(int j=1;j<=n;j++) cout<<pre[j]<<' ';
//		cout<<'\n';
		
		ll idx=upper_bound(pre+1,pre+n+1,m-del)-pre-1;
//		cout<<"当前的最大idx:"<<idx<<"\n";
		ans=max(ans,idx-i+1);
//		cout<<"当前变化量:"<<del<<'\n'<<'\n';
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll fff=arr[2]-arr[1];
	for(int i=3;i<=n;i++){
		if(arr[i]-arr[i-1]!=fff) is=true;
	}
//	cout<<is<<'\n';
	if(is) work();
	else ans=m/fff+1;
	
	cout<<ans;
	return 0;
}