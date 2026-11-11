#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int st[N];
int n,m;
vector<int> card;
vector<int> now;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		card.clear();
		//card.push_back(0);
		for(int j=1;j<=n;j++)	card.push_back(a[i]);
		for(int j=i;j<=n;j++){
			now.clear();
			//now.push_back(0);
			for(int q=0;q<int(card.size())&&card[q]!=a[j];q++){
				//cout<<card[q]<<' '<<a[j]<<endl;
				now.push_back(card[q]);
			}
			now.push_back(a[j]);
			card=now;
		}
		//for(int j=1;j<int(card.size());j++)	cout<<card[j]<<' ';
		for(int j=0;j<int(card.size());j++) st[card[j]]++;
	}
	for(int i=1;i<=m;i++)	printf("%d ",st[i]);
	return 0;
}
