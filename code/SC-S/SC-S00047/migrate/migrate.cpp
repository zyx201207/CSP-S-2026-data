#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[5005];
int solve(int x,int y){
	int len;
	int now=x;
	while(now<y){
		len++;
		int r=now;
		while(a[r]-a[now]<=d and r<=y) r++;
		now=r-1;
	}
	return len;
}
bool check(int x,int y){
	if(y-x<=2) return false;
	bool flag=false;
	vector<int> rd;
	int now=x;
	while(now<y){
		int r=now;
		rd.push_back(now);
		while(a[r]-a[now]<=d and r<=y) r++;
		if(now==r-1) return false;
		now=r-1;
	}
	for(int i=1;i<rd.size();i++){
		if((rd[i]-1>rd[0]) and (solve(rd[i]-1,y)+i==rd.size())){
			if(flag) return false;
			//cout<<solve(rd[i]-2,y)<<"\n";
			if((rd[i]-2>rd[0]) and (solve(rd[i]-2,y)+i==rd.size())) return false;
			flag=true;
		}
	}
	return flag;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<i<<" "<<j<<" "<<check(i,j)<<"\n";
				ans+=check(i,j);
			}
		}
		//cout<<solve(2,5)<<"\n";
	    cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/