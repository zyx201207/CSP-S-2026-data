#include<bits/stdc++.h>
using namespace std;int n,m,a[500005],ans[300005];
stack<int> s,s0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		bool f=0,v[300005];
		memset(v,0,sizeof(v));
		cin>>a[i];
		while(!s.empty()){
			if(!v[s.top()]){
				v[s.top()]=1;
				ans[s.top()]++;
			}
			if(s.top()==a[i]){
				f=1;
				break;
			}
			s0.push(s.top());
			s.pop();
		}
		while(!s0.empty()){
			s.push(s0.top());
			s0.pop();
		}
		if(!f){
			s.push(a[i]);
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
