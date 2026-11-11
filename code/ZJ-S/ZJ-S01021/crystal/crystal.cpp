#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
int ans=0;
vector<ll> a;
map<ll,int> cnt;
ll pre[N],lenth[N];
int check(ll pos){
	int l=0,r=pos,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if((ll)(lenth[pos]-lenth[mid-1])*a[pos]-(ll)(pre[pos]-pre[mid-1])<m) r=mid-1,res=mid;
		else if((ll)(lenth[pos]-lenth[mid-1])*a[pos]-(ll)(pre[pos]-pre[mid-1])==m){
			res=mid;
			break;
		}
		else l=mid+1;
		//cout<<pos<<"%%%%%"<<l<<" "<<r<<"   "<<(lenth[pos]-lenth[mid-1])-(pre[pos]-pre[mid-1])<<"%%%%\n";
	}
	return lenth[pos]-lenth[res-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		//cout<<"####\n";
	}
	sort(a.begin(),a.end());
	int len=0;
	for(int i=0;i<n;i++){
		if(a[i]!=a[i-1]){
			cnt[a[i-1]]=len;
			len=1;
		}
		else len++;
	}
	cnt[a[n-1]]=len;
	a.erase(unique(a.begin(),a.end()),a.end());
	pre[0]=a[0]*cnt[a[0]];
	lenth[0]=cnt[a[0]];
	for(int i=1;i<a.size();i++){
		pre[i]=(ll)(pre[i-1]+a[i]*cnt[a[i]]);
		lenth[i]=(ll)(lenth[i-1]+cnt[a[i]]);
	}
//	for(int i=0;i<a.size();i++){
//		cout<<cnt[a[i]]<<"$$$$"<<a[i]<<'\n';
//	}
	for(int i=0;i<a.size();i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
}
/*
__builtin_clz
priority_queue
*/