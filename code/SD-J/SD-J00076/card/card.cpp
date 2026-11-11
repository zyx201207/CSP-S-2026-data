#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],mp[500005],f1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		memset(ans,0,sizeof(ans));
		memset(f1,0,sizeof(f1));
		cnt=0;
		for(int j=i;j<=n;j++){
			int sum=0,f=0;
			for(int k=1;k<=cnt;k++){
				if(ans[k]==a[j]){
					sum=k;
					f=1;
					break;
				} 
			}
			if(f==1){
				for(int k=sum;k<=cnt;k++){
					ans[k]=0;
					cnt--;
				}	
			}
			ans[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			f1[ans[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(f1[j]==1){
				mp[j]++; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
}
