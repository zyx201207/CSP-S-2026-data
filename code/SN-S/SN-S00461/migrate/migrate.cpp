//SN-S00461 高子修 西安市第六中学 

/*
 * i can do dp!!!
 * wow
 * qiangqiangqiang
 * 
 * oh no
 * i do no how to does
 * !!!
 case!!!!
 * */
#include<bits/stdc++.h>
using namespace std;
int x[2000005];
//~ int zdl[2000005];
	int c,t;
int n,d;
int ans,ansstep;
void dfs(int start,int end,int now,int step){
	if(now==end){
		//~ cout<<ans<<" "<<ansstep<<" "<<step<<"\n";
		if(step==ansstep)ans++;
		else if(ansstep>step)ans=1,ansstep=step;
		return;
	}
	for(int i=now+1;i<=n;i++){
		if((x[i]-x[now])<=d&&i<=end)dfs(start,end ,i,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		//~ int n,d;
		if(c>=15&&c<=18)cout<<0<<"\n";
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int anss=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ansstep=0x3f3f3f3f,ans=0;
				dfs(i,j,i,0);
				if(ans==2)anss++;
				//~ if
			}
		}
		//~ if(ans==2
		cout<<anss<<"\n";
		//~ cout<<ans<<" "<<ansstep<<"\n";
	}
		
	return 0;
}
