#include<bits/stdc++.h>//»ºæ°¡À48
using namespace std;
int n,m,a[500005],ans[300005],ru[300005],x;
deque<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				q.push_back(a[i]);
				if(ru[a[i]]==1){
					q.pop_back();
					while(!q.empty()&&q.back()!=a[i]){
						x=q.back();
						ru[x]=0;
						q.pop_back();
					}
				}	
				else{
					ru[a[i]]=1;
				}
			}
			for(int i=j;i<=n;i++){
				ru[i]=0;
			}
			while(!q.empty()){
				x=q.back();
				ans[x]++;
				ru[x]=0;
				q.pop_back();
			}
		}	
	}
	else{
		for(int i=n;i>=1;i--){
			if(ru[a[i]]!=0){
				ans[i]=ans[i]+ru[a[i]]-i;
				ru[a[i]]=i;
				while(!q.empty()&&q.back()!=a[i]){
					x=q.back();
					ans[x]=ans[x]+ru[x]-i;
					ru[x]=0;
					q.pop_back();
				}
			}
			else{
				q.push_back(a[i]);
				ru[a[i]]=i;
			}
		}
		while(!q.empty()){
			x=q.back();
			ans[x]=ans[x]+ru[x];
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
