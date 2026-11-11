#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500005]={0};
int num[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		int cnt[300005]={0};
		stack<int> a;
		for(int j=i;j<=n;j++){
			if(cnt[card[j]]==1){
				while(!a.empty()){
					if(a.top()==card[j]){
						break;
					}
					else{
						num[a.top()]--;
						cnt[a.top()]=0;
						a.pop();
					}
				}
			}
			else{
				a.push(card[j]);
				cnt[card[j]]=1;
				num[card[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;


} 
