#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[500010];
int num[300010],tj[300010];
int card[500010];
void clear_card(int nn){
	int cn=cnt;
	for(int i=cn;i>=1;i--){
		if(card[i]==nn){
			num[a[i]]--;
			card[i]=0;
			cnt--;
			return;
		}num[a[i]]--;
		card[i]=0;
		cnt--;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int ii=1;ii<=n;ii++){
		memset(card,0,sizeof(card));
		memset(num,0,sizeof(num));
		cnt=0;
		//cout<<"\n"<<ii<<":\n";
		for(int i=ii;i<=n;i++){
			if(num[a[i]]==0){
				card[++cnt]=a[i];
				num[a[i]]++;
			}else{
				//cout<<'!';
				clear_card(a[i]);
				card[++cnt]=a[i];
				num[a[i]]++;
			}//for(int j=1;j<=cnt;j++){
				//cout<<card[j]<<" ";
			//}cout<<"\n!!!";
			//for(int j=1;j<=m;j++){
			//	cout<<num[j]<<" ";
			//}cout<<"\n";
		}for(int i=1;i<=m;i++){
			if(num[i]!=0)tj[i]++;
		}
	}//cout<<"\n";
	for(int i=1;i<=m;i++){
		cout<<tj[i]<<' ';
	}
	return 0;
} 
