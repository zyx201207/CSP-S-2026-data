#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[20000001]={0},pd[20000001]={0},p[20000001]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>pd[i];
	}
	for(int x=0;x<n;x++){
		int num=0;
		for(int i=0;i<n;i++){
			bool y=0;
			int pla=-1;
			for(int j=0;j<num;i++){
				if(pd[i]==p[j]){
					pla=j;
					y=1;
				}
			}
			if(y==1){
				for(int d=pla;d<n;d++){
					p[i]=-1;
				}
			}else{
				p[num]=pd[i];
				num++;
			}
		}
		for(int i=0;i<n;i++){
			pd[i]=pd[i+1];
		}
		pd[n]=0;
		for(int i=1;i<n;i++){
			if(p[i]!=0&&p[i]!=-1){
				ans[p[i]++];
			}
		}
	}
	for(int i=1;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;//delete my freopen and all debug words;
}

