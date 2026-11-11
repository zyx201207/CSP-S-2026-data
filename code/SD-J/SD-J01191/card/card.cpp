#include<bits/stdc++.h>
using namespace std;
int stk[500010],top=0;//m有多少种牌300010，n有多少张牌 500010
int is_appear_in[300010];//局内 
int ending[500010],card_queue[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card_queue[i];
	}
	for(int i=0;i<n;i++){
		for(int i=1;i<=m;i++){
			is_appear_in[i]=0;
		}
		for(int j=1+i;j<=n;j++){
			if(is_appear_in[card_queue[j]]!=0){
				int top_suan=top;
				top=is_appear_in[card_queue[j]]-1;
				for(int q=is_appear_in[card_queue[j]];q<=top_suan;q++){
					is_appear_in[stk[q]]=0;
				}
			}
			top++;
			stk[top]=card_queue[j];
			is_appear_in[card_queue[j]]=top;
		}
		for(int k=0;k<=top;k++){
			ending[stk[k]]++;
		}
		top=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ending[i]<<" ";
	}
	return 0;
}
