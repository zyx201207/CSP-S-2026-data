#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define Size 2000010
int n,d;
int pos[Size]; 
void specialA(){
	int dist=pos[2]-pos[1];
	int jump=d/dist;
//	cout<<dist<<' '<<jump<<endl;
	if(jump==0 or jump==1) cout<<0<<endl;
	else cout<<max(n-2*jump+1,0ll)<<endl;
}
void specialB(){
	cout<<0<<endl;
}
int cnt=0,min=10000;
void dfs(int st,int en,int now,int node){
	cout<<st<<' '<<en<<' '<<now<<endl;
	if(cnt==3) return ;
	if(now==en) {
		
		cnt++;
		return;
	}
	int i=now+1;
	while(pos[now]+d>=pos[i]){
		dfs(st,en,i);
		if(cnt==3) break;
	}
}
void violenceA(){
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pos[j]-pos[i]<=d) continue;
			for(int k=i;k<=j;k++)
				if(cnt==2) 
					res++;
			cout<<cnt<<endl;
			cnt=0;
		}
	}cout<<res<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;i++) pos[i]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pos[i];
		if(c<=6){
			violenceA();
		} 
		if(c==11 or c==12){
			specialA();
		}
		if(c==13 or c==14){
			specialB();
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
