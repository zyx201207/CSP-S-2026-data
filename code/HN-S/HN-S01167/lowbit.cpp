#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
int n,a[50];
struct b1t{
	int val[500010];
	#define lowbit(x) ((x)&(-(x)))
	void add(int x){
		while(x<=n){
			val[x]+=x;
			x+=lowbit(x);
		}
	}int ask(int x){
		if(x==0) return 0;
		int ret=0;
		while(x){
			ret+=val[x];
			x-=lowbit(x);
//			cout<<x<<' '<<ret<<endl;
		}//cout<<ret<<endl;
		return ret;
	}int ask(int l,int r){
		return ask(r)-ask(l-1);
	}
	#undef lowbit
}T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],T.add(a[i]);
	for(int i=1;i<=n;i++)
		cout<<T.ask(a[i])<<' ';
	cout<<endl;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<T.ask(x,y)<<endl;
	}
	return 0;
}/*
5 0
1 2 4 8 9

2
a[1]=1
a[2]=2
a[3]=0
a[4]=2
a[5]=0
*/

