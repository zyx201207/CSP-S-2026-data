#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int ans[5]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc[0]==xc[0]&&rc[1]==xc[1]){
		ans[1]++;
		if(rz[0]==xz[0]&&rz[1]==xz[1]){
			ans[2]++;
			if((rz[2]<='C'&&xz[2]<='C')||(rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D')){
				ans[3]++;
				int t=char((int)rz[2]+1);
				int tt=char((int)xz[2]+1);
				if(t==xz[2]||tt==rz[2])ans[4]++;
				if((rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D'))ans[4]++;
			}
		}
	}cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
} 
