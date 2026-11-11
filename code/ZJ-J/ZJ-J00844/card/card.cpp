#include<bits/stdc++.h>
using namespace std;
int const N=1e5+1;
int a[5*N];
bool b[3*N];
int c[3*N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>cards;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cards.clear();
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				cards.push_back(a[j]);
				b[a[j]]=1;
			}else{
				int k=cards.size()-1;
				while(cards[k]!=a[j]){
					b[cards[k]]=0;
					cards.erase(cards.end(),cards.end());
					k--;
				}				
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1) c[j]+=1;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
