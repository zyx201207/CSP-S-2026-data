#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e5+5;

int n,d;
int a[N];
int cnt,c;
void dfs(int pos,int r,int tot){
	if(tot>cnt)return ;
	if(pos==r){
		if(tot==cnt)c++;
		return ;
	}
	for(int i=pos+1;i<=r;i++){
		if(a[i]-a[pos]<=d){
			dfs(i,r,tot+1);
		}
	}
}
int bs(int l,int r,int x){
	int mid;
	while(l<r){
		mid=l+r+1>>1;
		if(a[mid]<=x){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
bool check(int l,int r){
	cnt=1;
	int pos=l;
	while(pos<r){
		int id=bs(pos+1,r,a[pos]+d);
		pos=id;
		cnt++;
//		cout<<pos<<" ";
	}
//	cout<<"1111\n";
	c=0;
	dfs(l,r,1);
	return (c==2);
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=9){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			} 
		}
		cout<<ans<<"\n";
	}
	else{
		cout<<0<<"\n";
	}
//	cout<<check(1,4);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	system("fc migrate.out migrate3.ans");
	int C,_;
	cin>>C>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
8pts
*/
