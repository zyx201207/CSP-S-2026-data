#include<bits/stdc++.h>
using namespace std;
deque<int> q;
int num[500005];
int id[500005];
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(id,0,sizeof(id));
	for(int j=1;j<=n;j++){
		memset(num,0,sizeof(num));
		while(!q.empty()){
			q.pop_back();
		}
		for(int i=j;i<=n;i++){
			int x;
			x=a[i];
			num[x]++;
			while(num[x]==2&&!q.empty()){
				int temp=q.back();
				q.pop_back();
				num[temp]--;
			}
			q.push_back(x);
		}
		for(int i=1;i<=m;i++){
			if(num[i]==1){
				id[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<id[i]<<" ";
	}
	return 0;
}
