#include<bits/stdc++.h>
using namespace std;
int a[500010]={};
int cnt[500010]={};
struct node{
	int vis=0;
	int it;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int v[50010]={};	
		node f[50010];
		int t=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]].vis==0){
				v[++t]=(a[j]);
				f[a[j]].vis=1;
				f[a[j]].it=t;
			}else{
				//cout<<t<<endl;
				int st=0;
				for(int k=1;k<=t;k++){
					if(v[k]==a[j]){
						v[k]=0;
						if(st==0){
							st=k;
						}
					}
				}
				for(auto k=st;k<=t;k++){
					v[k]=0;
				}
				//t=f[a[j]].it;
				v[t]=a[j];
				
			}
		}
		for(auto x:v){
			cnt[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
