#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ap[300010],ans[300010],a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	stack<pair<int,int> > s;
	for(int j=1;j<=n;j++){
	for(int i=j;i<=n;i++){
		int x=a[i];
		if(ap[x]==0){
			s.push({x,i});
			ap[x]++;
		}else{
			ap[x]--;
			while(s.top().first!=x){
				ap[s.top().first]--;
				s.pop();
				
			}
			s.pop();
		}
	}
	while(!s.empty()){
		ans[s.top().first]+=1;
		s.pop();
	}cout<<1;	
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}