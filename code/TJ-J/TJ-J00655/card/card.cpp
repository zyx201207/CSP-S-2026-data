#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],box[M],box2[M];
queue<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) box[j]=0;
		for(int j=i;j<=n;j++){
			if(box[a[j]]==0){
				box[a[j]]=1;
				q.push(a[j]);
			}
			else{
				while(q.front()!=a[j]){
					box[q.front()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			box2[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<box2[i]<<' ';
	return 0;
 } 
