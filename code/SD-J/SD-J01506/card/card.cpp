#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q.size();j++){
			
		}
	}
	return 0;
} 
