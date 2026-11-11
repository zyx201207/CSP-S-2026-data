#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-1e9;
		for(int i=0;i<n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<endl;
	}
	if(m==2){
		int maxx=-1e9;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}

