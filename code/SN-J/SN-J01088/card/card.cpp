#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;

int n,m;
int a[N];
int len;
int vis[N];
int ans[M];
int q[N];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			len++;
			q[len]=a[j];
			vis[a[j]]++;
			if(vis[a[j]]>1){
				while(vis[a[j]]>1||q[len]!=a[j]){
				vis[q[len]]--;
				len--;
			}
			}
			
		
			
		}
			for(int k=1;k<=len;k++){
			cout<<q[k]<<' ';
		}
		cout<<endl;
		
		
		
	}
	return 0;
}

