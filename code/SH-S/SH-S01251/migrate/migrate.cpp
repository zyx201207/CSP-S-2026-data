#include<bits/stdc++.h>
using namespace std;
int n,d,ans,cnt,num;
int f[2000009];
int bfs(int a,int b,int now){
	if(a==b){
		if(now==ans) cnt++;
		if(now<ans){
			ans=now;
			cnt=1;
		}
		return 0;
	}
	if(now>=ans) return 0;
	for(int i=a+1;i<=b;i++){
		if(f[i]-f[a]>d) break;
		bfs(i,b,now+1);
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0,sizeof(f));
		bool flag1=0; 
		for(int i=1;i<=n;i++){
			cin>>f[i];
			if(i>=3&&f[i]-f[i-1]!=f[i-1]-f[i-2]) flag1=1;
		}
		if(n>9&&flag1==0){
			int x=f[3]-f[2];
			int k=d/x;
			if(k==2) cout<<n-2<<endl;
			else cout<<0<<endl;
		}
		num=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				ans=100000009;
				cnt=0;
				bfs(i,j,0);
				if(cnt==2) num++;
			}
		}
		cout<<num<<endl; 
	}
	return 0;
} 
