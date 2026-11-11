#include<bits/stdc++.h>

using namespace std;
const int M=2e6+5;
int card[M],cards[M];
int box[2][M];
int ans[M];
int n,m;
void df(int step){
	if(step>n){
		for(int i=0;i<m;i++){
			ans[i]+=card[i];
			card[i]=0;	
		}
		return ;
	}
	for(int i=step;i<=n;i++){
		box[0][i]=cards[i];
		card[cards[i]]++;
		if(card[cards[i]]>=2){
			card[cards[i]]--;
			box[1][i]=cards[i];
			df(i+1);
			card[cards[i]]++;
			box[0][i]=cards[i];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>cards[i];
	for(int i=1;i<=n;i++){
		df(i-1);
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
} 
