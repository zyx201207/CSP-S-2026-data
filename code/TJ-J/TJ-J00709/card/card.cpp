#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],cnt[200002];
int zhan[500002],top;
bool book[200002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(book,false,sizeof(book));
		top=0;
		for(int i=k;i<=n;i++){
			if(book[a[i]]){
				while(zhan[top]!=a[i]){
					book[zhan[top]]=false;
					top--;
				}
			}
			else{
				top++;
				zhan[top]=a[i];
				book[zhan[top]]=true;
			}
		}
		for(int i=1;i<=m;i++){
			if(book[i]){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
