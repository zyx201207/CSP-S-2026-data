#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=3e2+10,M=2e6+10;
int c,t,n,d,x[M],ans,l[N],r[N],a[N][N];
int flag[N];
void fly(int d){
	memset(a,0,sizeof(a));
	memset(flag,0,sizeof(flag));
	int tot=0;
	a[d][0]=1;flag[d]=1;
	while(++tot){
		for(int i=1;i<=n;i++){
			if(a[i][tot-1]){
				a[l[i]][tot]+=a[i][tot-1];
				a[i][tot]-=a[i][tot-1];
				a[i+1][tot]+=a[i][tot-1];
				a[r[i]+1][tot]-=a[i][tot-1];
			}
		}
		for(int i=1;i<=n;i++){
			a[i][tot]+=a[i-1][tot];
//			cout<<a[i][tot]<<" ";
			if(a[i][tot]){
				if(!flag[i]&&a[i][tot]==2&&d<i) {ans++;}
				flag[i]=1;
			}
		}
//		cout<<'\n';
//		cout<<mp[5][1]<<" ";
		bool p=0;
		for(int i=1;i<=n;i++) 
			if(!flag[i]){
				p=1;
				break;
			}
		if(!p||tot>n) break;
	}
//	cout<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n>5000){
			int p=upper_bound(x+1,x+n+1,x[1]+d)-x-1-1;
			if(p!=2) cout<<"0\n";
			else cout<<2*(n-3)<<"\n";
		}
		for(int i=1;i<=n;i++){
			l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
//			cout<<l[i]<<" "<<r[i]<<"\n";
		}
		for(int i=1;i<=n;i++)
			fly(i);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/