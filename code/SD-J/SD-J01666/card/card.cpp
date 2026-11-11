#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],ans[300005];
bool lc[300005];
void pl(int s){
	for(int i=s;i<=n;i++){
		lc[c[i]]=true;
		for(int j=i+1;j<=n;j++){
			if(c[i]==c[j]){
				i=j;	
			}
		}
	}for(int i=1;i<=m;i++){
		if(lc[i]){
			lc[i]=false;
			ans[i]++;
		}
	}return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		pl(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}return 0;
}
