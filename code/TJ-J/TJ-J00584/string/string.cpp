#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll sum;
	ll id;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,sm=0;
	cin>>n;
	vector<node> a(n+5);
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i].sum>>c;
		a[i].id=int(c-'a')+1;
		sm+=a[i].sum;
	}
	if(sm%2==1){
		int ss=0;
		for(int i=1;i<=n;i++){
			ss+=a[i].sum;
			if(ss>sm/2){a[i].sum--;break;}
		}
	}//cout<<sm;
	sm/=2;
	vector<node> sa,sb;
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i].sum<=sm&&flag){
			sa.push_back(a[i]);
			sm-=a[i].sum;
		}else if(a[i].sum>sm&&flag){
			node ai=a[i];ai.sum=sm;
			sa.push_back(ai);
			a[i].sum-=sm;
			sb.push_back(a[i]);
			sm=0;
		}else sb.push_back(a[i]);
		if(sm==0)flag=0;
	}
	int l=0,r=sb.size()-1;
	ll ans=0;
	//cout<<(l<sa.size()&&r>=0);
	while(l<sa.size()&&r>=0){
		//cout<<"SNAIL";
		int minn=min(sa[l].sum,sb[r].sum);
		if(sa[l].id!=sb[r].id){
			ans+=minn;
		}
		sa[l].sum-=minn;
		sb[r].sum-=minn;
		if(sa[l].sum<=0)l++;
		if(sb[r].sum<=0)r--;
		//cout<<l<<" "<<r<<";";
	}cout<<ans;
	return 0;
}
