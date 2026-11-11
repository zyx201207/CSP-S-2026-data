#include<bits/stdc++.h>
using namespace std;
int v[500005],a[500005],ans[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				while(s.top()!=a[j]){
					v[s.top()]=0;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
			v[a[j]]=1;
		}
		while(s.size()){
			ans[s.top()]++;
			v[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
