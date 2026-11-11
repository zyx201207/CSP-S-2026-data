#include<map>
#include<stack>
#include<iostream>
using namespace std;
int a[300005],ans[200005],t[20005][20005];
stack<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			t[i][a[i]]++;
			s.push(a[i]);
			if(t[i][a[i]]>1){
				t[i][a[i]]=1;
				while(s.top()!=a[i]){
					int u=s.top();
					s.pop();
				}
			}
		}
		while(s.size()){
			int x=s.top();
			ans[x]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
