#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
int kk[500005];
int a[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		stack<int>z;
		int len=0;
		for(int i=1;i<=m;i++){
			vis[i]=false;
			kk[i]=0;
		}
		for(int i=k;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=true;
				kk[a[i]]=len;
				len++;
				z.push(a[i]);
			}
			else{
				for(int j=len-1;j>kk[a[i]];j--){
					vis[z.top()]=false;
					len--;
					z.pop();
				}
			}
		}
		while(!z.empty()){
			cnt[z.top()]++;
			z.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	
	return 0;
}
