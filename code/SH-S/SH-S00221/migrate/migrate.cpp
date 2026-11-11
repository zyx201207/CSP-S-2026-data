#include<bits/stdc++.h>
using namespace std;
int c,t,n,cnt=0,minn=1e9;
long long d,x[2000005],chan;
bool flag=1;
void solve1(){
	long long flymost=d/chan;
	long long longpath=2*flymost-1;
	if(longpath>n||chan>d||(d/chan==1&&d%chan==0)) cout<<"0"<<endl;
	else cout<<n-longpath<<endl;
} //8pts
void dfs(int start,int to,int len){
	if(start==to){
		if(len==minn) cnt++;
		if(len<minn){
			minn=len;
			cnt=1; 
		}
		return;
	}
	for(int i=to;i>=1;i--){
		if(x[i]-x[start]<=d) dfs(i,to,len+1);
	}
}//8pts
void solve2(){
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d) continue;
			else{
				cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		} 
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		flag=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1){
				chan=x[2]-x[1];
				long long cha=x[i]-x[i-1];
				if(cha!=chan) flag=0;
			}
		}
		if(flag==1) solve1();
		else{
			solve2();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
