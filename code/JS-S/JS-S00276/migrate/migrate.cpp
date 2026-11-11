#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ins insert
#define int long long
#define pii pair<long long,long long>
#define endl "\n"
int c,T,n,d,x[2000012];
int floyd[5012][5012],num[5012][5012];
void arrayChallenge(){//8'
	if(n==1){cout<<"0\n";return;}
	int val=x[2]-x[1];
	int state=d/val;
	if(state<=1){cout<<"0\n";return;}
	state*=2;
	cout<<max(n-state+1,0ll)<<endl;
}
void smallData(){
    rep(i,1,n)rep(j,1,n){
		floyd[i][j]=0x3f3f3f3f3f3f3f3f;
		num[i][j]=0;
	}
    rep(i,1,n)rep(j,1,n)if(j!=i&&labs(x[i]-x[j])<=d){
		floyd[i][j]=floyd[j][i]=1;num[i][j]=num[j][i]=1;
	}
	rep(i,1,n){floyd[i][i]=0;num[i][i]=1;}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)if(k!=i&&k!=j){
		if(floyd[i][k]+floyd[k][j]<floyd[i][j]){
			floyd[i][j]=floyd[i][k]+floyd[k][j];
			num[i][j]=num[i][k]*num[k][j];
			if(num[i][j]>2)num[i][j]=3;
		}
		else if(floyd[i][k]+floyd[k][j]==floyd[i][j]){
			num[i][j]+=num[i][k]*num[k][j];
			if(num[i][j]>2)num[i][j]=3;
		}
	}
	/*rep(i,1,n){
		rep(j,1,n)cout<<floyd[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	rep(i,1,n){
		rep(j,1,n)cout<<num[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	int ans=0;
	rep(i,1,n)rep(j,1,n)if(num[i][j]==2)ans++;
	cout<<ans/2<<endl;
}
int reachable(int cur){
	int l=cur+1,r=n,mid,ans=cur;
	while(l<=r){
		mid=l+(r-l)/2;
		if(x[mid]-x[cur]<=d){
			ans=mid;l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
void magicIsland(){
	int magicLeft=0,magicRight,cnt;
	rep(i,1,n){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			if(!magicLeft)magicLeft=i;
			magicRight=i;
		}
	}
	cnt=magicRight-magicLeft+1;
	if(cnt>2){cout<<"0\n";return;}
	if(cnt==1&&magicLeft==2){cout<<"0\n";return;}
	if(cnt==2)cout<<reachable(magicRight)-reachable(magicLeft-1)<<endl;
	if(cnt==1)cout<<reachable(magicRight)-reachable(magicLeft-2)<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>T;
    for(;T;--T){
		cin>>n>>d;
		rep(i,1,n)cin>>x[i];
		if(c==11||c==12)arrayChallenge();//8 points earned
		else if(c==13||c==14)magicIsland();
		else smallData();
	}
}
//diff -Z -B
//This is CSP-S. Be serious!
