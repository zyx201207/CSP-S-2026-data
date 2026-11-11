#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool b[300005];
stack<int>s;
int main(){
	freopen("card.in","r+",stdin);
	freopen("card.out","w+",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (b[a[j]]==0){
				b[a[j]]=1;
				s.push(a[j]);
			}
			else{
				while(1){
					if (s.empty())break;
					if (s.top()==a[j]) break;
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		for (int j=1;j<=m;j++){
			if (b[j]) ans[j]++;
			b[j]=0;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
