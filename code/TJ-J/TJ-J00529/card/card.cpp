#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],o,vis[500001];
queue<int>b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]){
					o=i-j+1;
				}
			}
			while(o!=0)b.pop();
			b.push(a[i]);
		}
		while(b.empty()!=0){
			vis[b.front()]++;
			b.pop();
		}
	}
	for(int i=1;i<=n;i++){
		cout<<vis[i]<<" ";
	}
    return 0;
}
