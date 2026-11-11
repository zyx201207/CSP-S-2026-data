#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int n;
ll m,arr;
ll a[N],idx=1;
unordered_map <ll,ll> mp;
ll num,ans,lastt,curr,cha;
struct Node{
	ll i;
	ll sheng;
}pos;

void init(int x){
	curr=a[x];
	num=mp[a[x]];
	lastt=m;
	pos={x,mp[a[x]]};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr;
		if(mp[arr]==0) a[idx++]=arr;
		mp[arr]++;
		ans=max(ans,mp[arr]);
	}
	sort(a+1,a+idx);
//	for(auto i : mp) cout<<i.first<<" "<<i.second<<"\n";
//	for(int i=1;i<idx;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	curr=a[1];
	num=mp[a[1]];
	lastt=m;
	pos={1,mp[a[1]]};
	
	for(int i=2;i<idx;i++){
		cha=a[i]-curr;
		cha*=num;
		if(a[i]>(m+curr)){
			init(i);
			continue;
		}
		
		while(cha>lastt){//回退 
			cha-=(a[i]-curr);//负值也没事
			//此处曾经写错了，和虚空搏斗了0.5h TvT 
			lastt+=(curr-a[pos.i]);
			pos.sheng--;
			if(pos.sheng==0){
				int tmp=pos.i+1;
				pos={tmp,mp[a[tmp]]};
			}
			num--;
		}
//		if(cha<=lastt){
		lastt-=cha;
		num+=mp[a[i]];
		ans=max(ans,num);
		curr=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/ 
