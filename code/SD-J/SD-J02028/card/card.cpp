#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5; 
const int M=5e5+5;
int n,m;
int a[M];
int kind[N],cnt[N];
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!dq.empty()){
			dq.pop_back();
		}
		memset(kind,0,sizeof(kind));
		for(int j=i;j<=n;j++){
			if(kind[a[j]]==0){
				dq.push_back(a[j]);
				kind[a[j]]=1;
			}
			else{
				while(dq.back()!=a[j]){
					kind[dq.back()]=0;
					dq.pop_back();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(kind[i]==1){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
