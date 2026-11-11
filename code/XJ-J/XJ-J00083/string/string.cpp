#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long move[n][2];
	for(int i=0;i<n;i++){
		cin>>move[i][0]>>move[i][1];
	}
	for(int i=0,j=n-1;i!=j;){
		if(move[i][1]!=move[j][1]){
			int z;
			if(move[i][0]<move[j][0]){
				z=move[i][0];
			}else{
				z=move[j][0];
			}
			ans+=z;
			move[i][0]-=z;
			move[j][0]-=z;
			if(move[i][0]==0){
				i++;
			}else{
				j--;
			}
		}else{
			int z;
			if(move[i][0]<move[j][0]){
				z=move[i][0];
			}else{
				z=move[j][0];
			}
			move[i][0]-=z;
			move[j][0]-=z;
			if(move[i][0]==0){
				i++;
			}else{
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
