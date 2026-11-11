#include<bits/stdc++.h>
#define int long long
#define fi first
#define N 1001000
#define M 100100
#define P 998244353
#define PX 1000000007
#define se second
#define all(x) x.begin(),x.end()
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mod(x) (((x%P)+P)%P)
using namespace std;
int n,m,ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2;
	int xi1,xi2,j1,j2;
	scanf("%lld %lld%c %lld %lld%c",&xi1,&j1,&c1,&xi2,&j2,&c2);
//	cout<<xi1<<' '<<j1<<' '<<c1<<' '<<xi2<<' '<<j2<<' '<<c2;
	bool ans1,ans2,ans3,ans4;
	ans1=(xi1==xi2);
	if(!ans1){
		cout<<"0000";
		return 0;
	}
	ans2=(j1==j2);
	if(!ans2){
		cout<<"1000";
		return 0;
	}
	ans3=(((c1=='E'&&c2=='F')||(c1=='F'&&c2=='E'))||((c1=='A'&&c2=='C')||(c1=='C'&&c2=='A')||(c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')));
	if(!ans3){
		cout<<"1100";
		return 0;
	}	
	ans4=(((c1=='E'&&c2=='F')||(c1=='F'&&c2=='E'))||((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')));
	if(!ans4){
		cout<<"1110";
		return 0;
	}	
	cout<<"1111";	
	return 0;
}

