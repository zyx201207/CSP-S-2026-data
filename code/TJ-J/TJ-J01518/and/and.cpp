#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005];
int su[32];
bool w[200005][32];
void dfs(int k,int s,bool bi[20]){
	if(k==m){
		ans=max(ans,s);
		return ;
	}
	for(int i=0;i<n;i++){
		if(bi[i]){
			continue;
		}
		bi[i]=1;
		dfs(k+1,s&a[i],bi);
		bi[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		bool bi[20];
		for(int i=0;i<n;i++){
			bi[i]=1;
			dfs(1,a[i],bi);
			bi[i]=0;
		}
		cout<<ans;
	}else if(m==1){
		int mx=0;
		for(int i=0;i<n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else{
//		for(int i=0;i<n;i++){
//			int ai=a[i];
//			int dw=0;
//			while(ai){
//				if(ai%2){
//					w[i][dw]=true;
//					su[dw]++;
//				}
//				dw++;
//				ai/=2;
//			}
//		}
//		for(int i=31;i>=0;i--){
//			if(su[i]>=m){
//				
//				for(int j=0;j<n;j++){
//					if(w[j][i]==0){
//						
//						for(int k=0;k<=31;k++){
//							
//							if(w[j][k]==1){
//								w[j][k]=0;
//								su[k]--;
//							}
//							
//						}
//						
//					}
//				}
//				
//			}
//		}
//		for(int i=0;i<=31;i++){
//			if(su[i]>=m){
//				ans++;
//			}
//			ans*=2;
//		}
//		cout<<ans;
		cout<<0;
	}
	return 0;
}
