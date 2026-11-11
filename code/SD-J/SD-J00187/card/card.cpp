#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],tmp[500010],ans[500010];
bool vis[500010]={true};
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	tmp[i]=a[i];
	} 
   for(int i=1;i<=n;i++){
   	stack<int> s;
   	    for(int j=i;j<=n;j++){
   	    	for(int k=i;k<j;k++){
   	    		if(a[k]==a[j]&&vis[k]==true){
   	    			for(int q=j-1;q>=k;q--){
   	    				s.pop();
   	    				vis[q]=false;
					} 
				}
			} 
			s.push(a[j]);
		} 
		while(!s.empty()){
			int x=s.top();
			s.pop();
			ans[x]++;
		}
		memset(vis,true,sizeof(vis));
   }
   for(int i=1;i<=m;i++){
   	cout<<ans[i]<<" ";
   } 
   cout<<endl;
	return 0;
}
