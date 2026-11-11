#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500005];
int cnt[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
	
		int k[300005]={0};
		//shang yi c wei zhi
		bool fu[500005]={0};
		
		for(int j=i;j<=n;j++){
			if(k[card[j]]==0) k[card[j]]=j;
			else {
				for(int l=k[card[j]];l<j;l++){
					fu[l]=1;
					k[card[l]]=0;
				}
				k[card[j]]=j;
			}
		}
		bool flag[300005]={0};
		for(int j=i;j<=n;j++){
			if(flag[card[j]]==0&&fu[j]==0){
				cnt[card[j]]++;
				flag[card[j]]=1;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
