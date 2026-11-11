#include <bits/stdc++.h>
using namespace std;
int n;
long long d;
long long a[2000005];
int ans,cnt;
int cal(int l,int r){
	for(int i=l+1;i<=r;i++){
		if((a[i]-a[i-1])>d)return 0;
	}
	int ans=0;
	int c=l;
	int e=l;
	while(e!=r){
		while(abs(a[c]-a[e])<=d && c<=r)c++;
		c-=1;
		e=c;
		ans++;
	}
	return ans;
}
void dfs(int now,int r,int step,int maxx){
	if(now==r){
		if(step==maxx){
			cnt++;
			return ;
		}
	}else if(step==maxx){
		return ;
	}
	for(int i=r;i>=now+1;i--){
		if(abs(a[i]-a[now])<=d){
			dfs(i,r,step+1,maxx);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				int num=cal(i,j);
				if(num==0)continue;
				dfs(i,j,0,num);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
