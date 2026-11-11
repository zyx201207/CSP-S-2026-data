#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int num; 
	int next;
}a[500010];
int n,m;
int ans[300010];
void game(int st){
	int now=st;
	while(now<=n){
		if(a[now].next!=0){
			now=a[now].next;
		}else{
			ans[a[now].num]++;
			now++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int need[300010]={0};
	int x;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i].num=x;
		a[need[x]].next=i;
		need[x]=i;
	} 
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
