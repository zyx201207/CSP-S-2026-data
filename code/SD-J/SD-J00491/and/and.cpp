#include<bits/stdc++.h>
using namespace std;
int aa1[200001];
bool vis[200001];
int ans;
int nn1,mm1;
void dfs(int cnt,int su){
	if(su==mm1){
		ans=max(ans,cnt);
		return ;
	}
	for(int ii1=1;ii1<=nn1;ii1++){
		if(!vis[ii1]){
			vis[ii1]=1;
			dfs((cnt&aa1[ii1]),su+1);
			vis[ii1]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>nn1>>mm1;
    for(int ii1=1;ii1<=nn1;ii1++){
    	cin>>aa1[ii1];
	}
    if(nn1<=20){
    	dfs(2147483647,0);
    	cout<<ans<<'\n';
	}else{
		if(mm1==1){
			for(int ii1=1;ii1<=nn1;ii1++){
				ans=max(ans,aa1[ii1]);
			}
			cout<<ans<<'\n';
		}else{
			if(mm1==nn1){
				ans=2147483647;
				for(int ii1=1;ii1<=nn1;ii1++){
					ans=(ans&aa1[ii1]);
				}
				cout<<ans<<'\n';
			}else if(mm1==2){
    			dfs(2147483647,0);
    			cout<<ans<<'\n';
			}else{
				bool ff1=1,ff2=0;
				for(int ii1=1;ii1<=nn1;ii1++){
					if(aa1[ii1]!=ii1-1){
						ff1=0;
						break;
					}
				}
				for(int ii1=0;ii1<=18;ii1++){
					if(nn1==pow(2,ii1)){
						ff2=1;
						break;
					}
				}
				if(ff1==1&&ff2==1){
					cout<<(nn1-pow(2,mm1))<<'\n';
				}
			}
		}
	}
	return 0;
}

