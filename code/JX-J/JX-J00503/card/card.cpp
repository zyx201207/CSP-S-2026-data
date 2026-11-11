#include<iostream>
using namespace std;

int N,M;
int n[500005];
int nex[500005];
int ans[500005];
int b[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>N>>M;
	for(int i=1;i<=N;i++)cin>>n[i];
	for(int i=N;i>=1;i--){
		/*
		nex[b[n[i]]]=i;
		b[n[i]]=i;
		 */
		nex[n[i]]=max(nex[n[i]],i);
	}
	for(int i=1;i<=N;i++){
		int p=i;
		while(p<=N){
			ans[n[p]]++;
			if(nex[n[p]]){
				p=nex[n[p]]+1;
			}else{
				p++;
			}
		}
	}
	for(int i=1;i<=M;i++)cout<<ans[i]<<' ';
	cout<<endl;
}
