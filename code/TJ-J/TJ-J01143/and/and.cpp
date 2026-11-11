#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int N,M;
int aa[MAXN];
bool last[34][MAXN];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=N;i++) last[31][i]=true;
	int max=-1;
	for(int k=30;k>=0;k--){
		int cnt=0,add=0;
		for(int i=1;i<=N;i++){
			if(aa[i]&(1<<k)) {
				cnt++;
				if(max==-1) last[k][i]=true;
				else {
					if(last[k+1][i]){
						last[k][i]=true;
						add++;
					}
				} 
			}
		}
		if(max==-1){
			if(cnt>=M){
				max=k;
				ans|=(1<<k);
			}
		}else{
			if(add>=M){
				ans|=(1<<k);
			}else{
				for(int i=1;i<=N;i++) last[k][i]=last[k+1][i];
			}
		}
	}
	cout<<ans;
	
	return 0;
}
