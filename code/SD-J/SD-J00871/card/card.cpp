#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],v[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		while(!q.empty()) q.pop();
		for(int j=1;j<=m;j++){
			v[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				q.push(a[j]);
				v[a[j]]++;
			}
			else{
				int e=1,x=q.size(),f=0;
				while(e<=x){
					if(q.front()==a[j]){
						v[q.front()]--;
						q.pop();
						f=1; 
					}
					else if(f==1){
						v[q.front()]--;
						q.pop();
					}
					else{
						q.push(q.front());
						q.pop();
					}
					e++;
				}
				q.push(a[j]);
				v[a[j]]++;
			} 
		}
		for(int j=1;j<=m;j++){
			if(v[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

