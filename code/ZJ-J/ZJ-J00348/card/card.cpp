#include<bits/stdc++.h>
using namespace std;
bool had[300005];
int a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			had[j]=false;
		}
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(had[a[j]]==true){
				while(s.top()!=a[j]){
					had[s.top()]=false;
					s.pop();
				}
			}else{
				s.push(a[j]);
				had[a[j]]=true;
			}
		}
		for(int i=1;i<=m;i++){
			if(had[i]==true){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}