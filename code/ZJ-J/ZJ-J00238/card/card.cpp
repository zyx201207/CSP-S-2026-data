#include<bits/stdc++.h>
using namespace std;
bool hasit[500005];
int ans[500005],a[500005];
int main(){
	ios::sync_with_stdio();
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i-1]<=a[i])) flag1=false;
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=m;j++){
				ans[j]++;
			}
		}
	}
	else
		for(int i=1;i<=n;i++){
			for(int i=1;i<=m;i++) hasit[i]=false;
			stack<int> s;
			for(int j=i;j<=n;j++){
				if(hasit[a[j]]){
					int x;
					do{
						x=s.top();
						s.pop();
						hasit[x]=false;
					}while(x!=a[j]);
				}
				s.push(a[j]);
				hasit[a[j]]=true;
			}
			for(int i=1;i<=m;i++){
				if(hasit[i]) ans[i]++;
			}
		}
	for(int i=1;i<=m;i++) cout<<ans[i]<<(i==m?"":" ");
	return 0;
}

