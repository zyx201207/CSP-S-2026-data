#include<bits/stdc++.h>
using namespace std;
struct ad{
	int flag,id;
};
ad b[205];
int a[505],ans[205];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> s;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++){
	    	s.push(a[j]);
	    	if(b[a[j]].flag=1){
	    		for(int k=1;k<=j-b[a[j]].id;k++) s.pop();
			}
	    	b[a[j]].flag=1;
	    	b[a[j]].id=j;
	
		}
	}
	while(s.size()>0){
		ans[s.top()]++;
	}
	for(int k=1;k<=m;k++){
		if(ans[k]!=0) cout<<ans[k];
	}
	return 0;
}
