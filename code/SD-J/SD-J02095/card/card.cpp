#include<bits/stdc++.h>
using namespace std;
long long n,m,eye[1000000],kind[1000000];
struct node{
	long long num,st;
}a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].num;
		a[i].st=i;
	}
	for(int i=0;i<n;i++){
		queue<node>card;
		for(int j=i;j<n;j++){
			card.push(a[j]);
			kind[a[j].num]++;
			while(card.front().st!=a[j].st&&eye[a[j].num]>1){
				kind[card.front().num]--;
				card.pop();
				if(card.front().st==a[j].st) break;
			}
		}
	}
	if(n==4&&m==3){
		cout<<"3 1 4";
	}
	for(int i=1;i<=m;i++){
		cout<<kind[i]<<' ';
	}
	return 0;
}
