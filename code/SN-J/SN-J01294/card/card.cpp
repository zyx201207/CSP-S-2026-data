//SN-J01294
#include<bits/stdc++.h>
using namespace std;
int n,m,fir[300005],a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(fir,0,sizeof(fir));
		for(int j=i;j<=n;j++){
			if(fir[a[j]]==0){
				q.push(a[j]);
				fir[a[j]]=1;
			}else{
				while(!q.empty()){
					if(q.top()==a[j]){
						q.pop(); 
						break;
					}
						q.pop();
				}
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
