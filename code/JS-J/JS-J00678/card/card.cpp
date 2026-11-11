#include<bits/stdc++.h>
using namespace std;
int m,n,a[300007],ans[300007];
vector<int> ls;
int found(int a,int b){
	for(int i=0;i<b;i++){
		if(ls[i]==a){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		cout<<n;
		return 0;
	}
	int size;
	for(int i=0;i<n;i++){
		ls.clear();
		size=0;
		for(int j=i;j<n;j++){
			if(found(a[j],size)==-1){
				ls.push_back(a[j]);
				size++;
			}else{
				for(int k=ls.size()-1;k>found(a[j],size);k--){
					ls.erase(ls.begin()+k);
					size--;
				}
			}
		}
		for(int u=1;u<=m;u++){
			if(find(ls.begin(),ls.end(),u)!=ls.end()){
				ans[u]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
