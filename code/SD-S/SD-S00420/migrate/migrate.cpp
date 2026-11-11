#include<bits/stdc++.h>
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(x) (x).begin(),(x).end()
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define cout(x) cout<<fixed<<setprecision(x)
#define int LL

using namespace std;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=2e6+5;
int n,tol[N],tor[N];
LL d,x[N],ans,jumpl[N],jumpr[N];

LL queryl(int l,int r,bool flag){
	if(l>r) return 0;
	if(flag){
		return (r-l)+jumpl[l];
	}
	return (r-l+1);
//	return sl[r]-sl[l-1];
}
LL queryr(int l,int r,bool flag){
	if(l>r) return 0;
	if(flag){
		return (r-l)+jumpr[r];
	}
	return (r-l+1);
//	return sr[r]-sr[l-1];
}

void clear(){
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		jumpl[i]=jumpr[i]=1;
//		cout<<x[i]-x[i-1]<<" ";
	}
//	cout<<"\n";
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&x[j+1]-x[i]<=d){
			j++;
		}
		tor[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>1&&x[i]-x[j-1]<=d){
			j--;
		}
		tol[i]=j;
	}
	for(int i=1;i<=n-2;i++){
		if(tor[i]>i&&tor[tor[i]]!=tor[tor[i]-1]){
			jumpl[tor[i]]+=jumpl[i];
//			cout<<i<<"->"<<tor[i]<<"\n";
		}
	}
	for(int i=n-2;i>=1;i--){
		if(tor[i]>i&&tor[tor[i]]==tor[tor[i]-1]){
			jumpl[tor[i]]+=jumpl[i];
//			cout<<i<<"->"<<tor[i]<<"\n";
		}
	}
	for(int i=n;i>=3;i--){
		if(tol[i]<i&&tol[tol[i]]!=tol[tol[i]+1]){
			jumpr[tol[i]]+=jumpr[i];
		}
	}
	for(int i=3;i<=n;i++){
		if(tol[i]<i&&tol[tol[i]]==tol[tol[i]+1]){
			jumpr[tol[i]]+=jumpr[i];
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<jumpl[i]<<" "<<jumpr[i]<<"\n";
//	}
	ans=0;
	for(int i=2;i+2<=n;i++){
		ans+=(LL)queryl(tol[i+1],min(tol[i+2]-1,i-1),tol[i+1]==tol[i])*queryr(max(tor[i-1]+1,i+2),tor[i],tor[i+1]==tor[i]);
//		cout<<i<<","<<i+1<<":"<<queryl(tol[i+1],min(tol[i+2]-1,i-1),tol[i+1]==tol[i])<<"*"<<queryr(max(tor[i-1]+1,i+2),tor[i],tor[i+1]==tor[i])<<"="<<(LL)queryl(tol[i+1],min(tol[i+2]-1,i-1),tol[i+1]==tol[i])*queryr(max(tor[i-1]+1,i+2),tor[i],tor[i+1]==tor[i])<<" ; ";
//		cout<<tol[i+1]<<","<<min(tol[i+2]-1,i-1)<<" ; "<<max(tor[i-1]+1,i+2)<<","<<tor[i]<<"\n";
	}
	cout<<ans<<"\n";
}
signed main(){
//	system("fc migrate1.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1,c;cin>>c>>t;
	while(t--) clear(),solve();
	return 0;
}
/*
0 1
10 75
73 94 125 165 187 214 218 275 306 343

0 1
10 54
85 92 101 121 138 155 207 243 261 282 

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

	jumpl[1]=jumpr[n]=1;
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]==d){
			jumpl[i]=jumpl[i-1]+1;
		}else{
			jumpl[i]=1;
		}
	}
	for(int i=n-1;i>=1;i--){
		if(x[i+1]-x[i]==d){
			jumpr[i]=jumpr[i+1]+1;
		}else{
			jumpr[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		sl[i]=sl[i-1]+jumpl[i];
		sr[i]=sr[i-1]+jumpr[i];
	}
	ans=0;
	for(int i=1;i<=n-3;i++){
		if(x[i+2]-x[i]<=d&&x[i+3]-x[i]>d){
			if(tor[i+1]>=i+3){
				ans+=(LL)jumpl[i]*(sr[tor[i+1]]-sr[i+2]);
			}
		}
	}
	for(int i=4;i<=n;i++){
		if(x[i]-x[i-2]<=d&&x[i]-x[i-3]>d){
			if(tol[i-1]<i-3){
				ans+=(LL)jumpr[i]*(sl[i-4]-sl[tol[i-1]-1]);
			}
		}
	}
	
18:05
*/

