#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int num;
}nrr[200005];
int t=0;
int crr[200005]={};
bool cmp(Node a,Node b){
	return a.num>b.num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nrr[i].num;
	}
	sort(nrr+1,nrr+n+1,cmp);
	int ans;
	for(int i=1;i<=n;i++){
		if(t<m){
			t++;
			crr[t]=nrr[i].num;
			if(t==1){
				ans=nrr[i].num;
			}else{
				ans=ans&nrr[i].num;
			}
		}else{
			int an=-1,k;
			for(int j=1;j<=t;j++){
				int ans1=0;
				for(int x=1;x<=t;x++){
					for(int j=1;j<=t;j++){
						if(j!=x){
							ans1=ans1&crr[j];
						}
					}
					if(ans1>an){
						an=ans1;
						k=x;
					}
				}
			}
			if(an&nrr[i].num>ans){
				ans=an&nrr[i].num;
				crr[k]=nrr[i].num;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
