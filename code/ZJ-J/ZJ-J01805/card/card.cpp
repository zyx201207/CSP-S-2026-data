#include<bits/stdc++.h>
using namespace std;
long long n,m,sx[500005],ans[300005],key[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sx[i];
	}
	for(int i=1;i<=n;i++){
		queue<long long>ma;
        queue<long long>ma1;
		for(int j=1;j<=m;j++){
			key[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(key[sx[j]]==1){
				while(ma.front()!=sx[j]){
					ma1.push(ma.front());
					ma.pop();
				}
				while(ma.size()){
					key[ma.front()]=0;
					ma.pop();
				}
				while(ma1.size()){
					ma.push(ma1.front());
					ma1.pop();
				}
			}
			ma.push(sx[j]);
			key[sx[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]=ans[j]+key[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
