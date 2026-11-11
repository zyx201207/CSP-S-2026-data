#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int N,M;
int aa[MAXN];
int cnt[MAXM];
bool ins[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>aa[i];
	
	for(int i=1;i<=N;i++){
		stack<int> st;
		for(int j=1;j<=M;j++) ins[j]=false;
		for(int j=i;j<=N;j++){
			if(ins[aa[j]]){
				while(st.top()!=aa[j]){
					ins[st.top()]=false;
					st.pop();
				}
			}else{
				ins[aa[j]]=true;
				st.push(aa[j]);
			}
		}
		for(int i=1;i<=M;i++){
			if(ins[i]) cnt[i]++;
		}
	}
	for(int i=1;i<=M;i++) cout<<cnt[i]<<" ";
	
	
	return 0;
}
