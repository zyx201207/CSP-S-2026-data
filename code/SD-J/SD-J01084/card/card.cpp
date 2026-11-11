#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m;
struct Node{
	int num;
	int last;
	int next;
}card[N];
int cnt[N];
int Map[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		card[i].last=i;
		card[i].next=i;
		cin>>card[i].num;
		if(Map[card[i].num]){
			card[i].last=Map[card[i].num];
			card[card[i].last].next=i;
		}
		Map[card[i].num]=i;
	}
	for(int l=1;l<=n;l++){
		bool now[N];
		for(int i=1;i<=m;i++){
			now[i]=0;
		}
		for(int r=l;r<=n;){
			if(card[r].next!=r){
				r=card[r].next;
				if(now[card[r].num]==0){
					now[card[r].num]=1;
					cnt[card[r].num]++;
				}
			}else{
				if(now[card[r].num]==0){
					now[card[r].num]=1;
					cnt[card[r].num]++;
				}
				r++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

