#include<bits/stdc++.h>
using namespace std;
int t[300005],a[500005];
int n,m;
stack<int>b;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=a[i];
		/*for(int j=i;j<=n;j++){
			if(b[j]==k){
				f=1;
			}
		}*/
		while(!b.empty()){
			t[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}

	return 0;
}
