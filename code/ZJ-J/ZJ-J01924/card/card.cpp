#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int a[maxn];
int dis[maxn];
int disdis[maxn];
int sum[maxn];
int sl[maxn];
int sr[maxn];
int main(){
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				sl[i]=j;
				break;
			}
		}
		for(int j=n;j>=1;j--){
			if(a[j]==i){
				sr[i]=j;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++){
			dis[j]=1;
		}
		for(int j=1;j<=m;j++){
			disdis[j]=0;
		}
		
		for(int j=1;j<=m;j++){
			if(i>sl[j]){
				bool flag=0;
				int l2;
				for(int k=sl[j]+1;k<=n;k++){
					if(a[k]==j){
						l2=k;
						flag=1;
						break;
					}
				}
				if(flag==1){
					sl[j]=l2;
				}else{
					continue;
				}
			}
			
			for(int k=sl[j]+1;k<=sr[j]-1;k++){
				dis[k]=0;
			}
		}
		for(int j=i;j<=n;j++){
			if(dis[j]==1){
				disdis[a[j]]=1;
			}
		}
		
		for(int j=1;j<=m;j++){
			if(disdis[j]==1){
				sum[j]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
