#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[300005];
int card[200005];
int card2[200005];
int last[300005];
int first[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
		if(first[card[i]]==0){
			first[card[i]]=i;
		}
		last[card[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(card2,0,sizeof(card2));
		for(int j=1;i<=m;i++){
			if(last[j]>=i){
				for(int k=first[j];k<last[j];k++)card2[k]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(card2[last[j]]!=1&&last[j]>=i){
				cnt[j]++;
			}
		}
		for(int j=i;j<=n;j++){
			if(card[j]==card[i]){
				first[card[i]]=j;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
