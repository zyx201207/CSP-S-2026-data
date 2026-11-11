#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,cardi[N],cards[N],sumc[N];
void solve(int pos){
	int tou=1,wei=0;
	memset(cardi,0,sizeof(cardi));
	for(int i=pos;i<=n;i++){
		for(int j=tou;j<=wei;j++){
			if(cardi[j]==cards[i]) wei=j-1;	
		}
		cardi[++wei]=cards[i];
	}
	for(int i=tou;i<=wei;i++){
		sumc[cardi[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<sumc[i]<<" ";
	}
	return 0;
} 
