#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+5;
bool poi[N];//记录1-m点数是否出现 
int id[N];//记录每个点数第一次进入牌桌的位置 
int a[N],top=0;//牌桌栈
int ans[N];//答案数组 
int b[N],n,m;//牌库 
void game(int n1){
	for(int i=n1;i<=n;i++){
		int card=b[i];
		if(!poi[card]){
			a[++top]=card;	
			poi[card]=1;
			id[card]=top;
		}
		else{
			for(int j=id[card]+1;j<=top;j++){
				poi[a[j]]=0;
			}
			top=id[card];
		}
	}
	for(int i=1;i<=top;i++){
		ans[a[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==2){
		if(b[n]!=b[n-1]){
			if(b[n]==1){
				cout<<n<<" "<<n-1;
			}
			else{
				cout<<n-1<<" "<<n;
			}
		}
		else{
			if(b[n]==1){
				cout<<n<<" "<<0;
			}
			else{
				cout<<0<<" "<<n;
			}
		}
		return 0;
	}
	for(int i=1;i<n;i++){
		game(i);
		top=0;
		memset(poi,0,sizeof(poi));
	}
	ans[b[n]]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
