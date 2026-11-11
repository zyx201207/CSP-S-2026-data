#include<bits/stdc++.h>
#define ll long long
#define VI vector<int>
#define endl '\n'
#define up(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
const int NN=5e5+5;
ll n,m,a[NN],lft,val,sz,lst,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m; lst=m;
	up(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	lft=1;
	up(i,1,n){
		ll gap=a[i]-val;
//		cout<<i<<" "<<a[i]<<" "<<gap<<" "<<val<<endl;
		while(lst<gap*sz&&sz>0){
			lst+=val-a[lft];
			sz--,lft++;
		}
		lst-=gap*sz,val=a[i],ans=max(ans,sz+1);
//		cout<<lst<<endl;
		sz++;
	}
	cout<<ans;
	return 0;
}
/*
2 1
1 3
*/