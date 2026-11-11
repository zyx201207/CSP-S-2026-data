#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;

long long a[N];

long long cnt=0;long long n,m;
long long mn=INT_MAX;
void dfs(int st,int en,int nst,int step){
//	cout<<st<<" "<<en<<" "<<nst<<" "<<cnt<<" "<<step<<"\n";
	if(en-st<3)return ;
	if(nst==en&&step<mn){cnt=1;mn=step;return ;}
	if(nst==en&&step==mn){cnt++;return ;}
	if(cnt>=3)return ;
	
	for(int i=nst+1;i<=en;i++){
		if(a[i]-a[nst]<=m)dfs(st,en,i,step+1);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=9){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					cnt=0,mn=INT_MAX;
					dfs(i,j,i,0);
//					cout<<cnt<<"\n";
					ans+=(cnt==2);
//					cout<<i<<" "<<j<<" "<<ans<<"\n";
				}
			}
			cout<<ans<<"\n";
		}else{
			vector<int> v(n+5);
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(i>=4){
					if(a[i]-a[i-1]>m)continue;
					if(a[i-1]-a[i-3]>m)continue;
					if(a[i]-a[i-3]<=m)continue;
					v[i]=1;
					for(int j=i;;j--){
						if(j>=5&&(a[i]-a[j-4]>m&&a[j-2]-a[j-4]>m)||(a[i]-a[j-1]<=m&&a[i]-a[j-2]>m))v[i]+=v[j-1];
						else break;
					}
	//				cout<<v[i]<<"\n";
					ans+=v[i];
				}
			}
			cout<<ans<<"\n";
		}
		
		
	}
	return 0;
}
/*
16:45 kan ti



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

*/
