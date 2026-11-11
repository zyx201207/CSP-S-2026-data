#include<bits/stdc++.h>
using namespace std;
int c,ans,e,mmin,n,d;
int a[2000010];
void dfs(int x,int cnt,int end){
	if(x==end){
		if(cnt<mmin){
			ans=1;
			mmin=cnt;
		}
		else if(cnt==mmin){
			ans++;
		}
		return;
	}
	if(x>end){
		return;
	}
	int i=x+1;
	while(a[i]-a[x]<=d){
		dfs(i,cnt+1,end);
		i++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		e=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			if(a[n]-a[1]<=d)
				cout<<0<<"\n";
			else{
				cout<<1<<"\n";
			}
			continue;
		}
		if(c==11||c==12){
			if(a[2]-a[1]>d){
				cout<<0<<"\n";
			}
			else{
				cout<<n-d/(a[2]-a[1])*2+1<<"\n";
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0,mmin=INT_MAX;
				dfs(i,0,j);
				if(ans==2) e++;
			}
		}
		cout<<e<<"\n";
	}
	return 0;
}
