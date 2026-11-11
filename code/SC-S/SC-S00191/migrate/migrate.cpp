#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6+5;
long long a[maxn];
int t,n,d;
void solve(){
	int zc[maxn]={0};
	cin>>n>>d;
	int c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=a[i]-a[i-1];
	}
	int fly=d/c;
	int j=1;
	for(int i=1;i<=n-1;i++){
		if(i<=fly&&(i-fly)%4==0&&i%fly==0){
			continue;
		}
		zc[j]=i;
		j++;
	}
	long long ans=0;
	for(int i=1;i<=j;i++){
		ans+=n-zc[j]+1;	
	}
	cout<<ans<<endl;
}
int main(){
	int m;
	freopen("migrate.in",'r',stdin);
	freopen("migrate.out",'w',stdout);
	cin>>m>>t;
	while(t--){
		solve();
	}
	return 0;	 
}