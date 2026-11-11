#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int n,m,p[maxn],ans[maxm],l[maxn],v=n,win[maxn],cnt=0;
bool f=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) l[j]=p[j];
		for(int j=2;j<=n;j++){
			for(int k=j-1;k>=1;k--){
				int s=l[j];
				if(s==l[k]&&s!=0){
					for(int t=k;t<=j;t++){
						l[t]=0;
					}
					for(int r=1;r<=500;r++) if(s==win[r]) ans[s]--;
					ans[s]++;
					win[cnt]=s;
					cnt++;
					l[n+1]=s;	
				}
			}
			if(f==1) break;
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(l[k]==j) ans[j]++;
			}	
		}
		cnt=0;
		for(int j=1;j<=n;j++) l[j]=0; 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
