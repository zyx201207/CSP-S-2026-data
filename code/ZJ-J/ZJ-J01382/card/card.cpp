#include<bits/stdc++.h>
using namespace std;
long long a[555555],b[333333],c[333333];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		queue<int>q1,q2;
		for(int j=i;j<=n;j++){
			if(c[a[j]]){
				bool f=1;
				for(int k=i;k<=j;k++){
					if(f){
						if(a[k]==a[j]){
							f=0;
							c[a[k]]=0;
							continue;
						}
						int t=q1.front();
						q1.pop();
						q2.push(t);
					}
					else{
						c[a[k]]=0;
						q1.pop();
					}
				}
			}
			q1.push(a[j]);
			c[a[j]]=1;
			if(!q2.empty())q1=q2;
			while(!q2.empty())q2.pop();
		}
		while(!q1.empty()){
			int t=q1.front();
			q1.pop();
			b[t]++;
		}
		for(int j=1;j<=m;j++)c[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}