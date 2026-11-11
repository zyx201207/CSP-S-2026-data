#include<bits/stdc++.h>
using namespace std;
int nn1,mm1,aa1[500001];
int zhan[500001];
int tong[300001];
bool vis[300001];
int ztong[300001];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>nn1>>mm1;
	for(int ii1=1;ii1<=nn1;ii1++){
		cin>>aa1[ii1];
	}
	for(int ii1=1;ii1<=nn1;ii1++){
		int top=0,fei=0x7fffffff;
		memset(tong,0,sizeof(tong));
		memset(zhan,0,sizeof(zhan));
		for(int jj1=ii1;jj1<=nn1;jj1++){
			if(tong[aa1[jj1]]==0||(tong[aa1[jj1]]>fei&&vis[aa1[jj1]]==0)){
				top++;
				zhan[top]=aa1[jj1];
				tong[aa1[jj1]]=top;
				vis[aa1[jj1]]=1;
			}
			else{
				top=tong[aa1[jj1]];
				fei=top;
			}
		}
		for(int jj1=1;jj1<=top;jj1++){
			ztong[zhan[jj1]]++;
		}
	}
	for(int jj1=1;jj1<=mm1;jj1++){
		cout<<ztong[jj1]<<' ';
	}
	return 0;
}

