#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500005];
bool desk[500005];
int ans[500005];
void deal(int a){
	for ( int i=0;i<n; i++){
		if(desk[i]==true&&card[i]==a){
			for ( int j=i+1; j<n; j++)desk[j]=false;
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> card[i];
	}
	for(int t=0; t<n; t++){
		for(int i=0; i<n; i++){
			desk[i]=true;
			deal(card[i]);
		}
		for(int i=0; i<n; i++){
			ans[i]+=desk[i];
		}
	}
	for ( int i=0; i<n; i++){
		cout << ans[i] << ' ';
	}
}
