#include<bits/stdc++.h>
using namespace std;
string n,m;
string numn,numm;
bool vis[5]={0,0,0,0,0};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>numn;
	cin>>m>>numm;
	string vn,vm,pn,pm;
	vn={numn[0],numn[1]};
	vm={numm[0],numm[1]};
	pn=numn[2];
	pm=numm[2];
	if(n!=m){
		for(int i=1;i<=4;i++){
			cout<<vis[i];
		}
		return 0;
	}else{
		vis[1]=1;
		if(vn==vm){
			vis[2]=1;
			if(pn[0]>='A'&&pn[0]<='C'&&pm[0]>='A'&&pm[0]<='C'||pn[0]>='D'&&pn[0]<='F'&&pm[0]>='D'&&pm[0]<='F'){
				vis[3]=1;
				if(pn[0]-pm[0]==1&&pn[0]!='D'||pm[0]-pn[0]==1&&pm[0]!='D'){
					vis[4]=1;
				}else{
					for(int i=1;i<=4;i++){
						cout<<vis[i];
					}
					return 0;
				}
			}else{
				for(int i=1;i<=4;i++){
					cout<<vis[i];
				}
				return 0;
			}
		}else{
			for(int i=1;i<=4;i++){
				cout<<vis[i];
			}
			return 0;
		}
	}
	for(int i=1;i<=4;i++){
		cout<<vis[i];
	}
	return 0;
}