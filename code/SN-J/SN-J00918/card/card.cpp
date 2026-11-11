#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int tong[100010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			if(v.empty()){
				v.push_back(a[i]);
			}
			else{
				bool f=true;
				for(int k=1;k<=v.size()-1;k++){
					if(v[k]==a[j]){
						f=0;
						break;
					}
				}
				if(f==0){
					continue;
				}
				if(v[v.size()-1]!=a[j]){
					v.push_back(a[j]);
				}
			}
		}
		for(int j=0;j<v.size();j++){
			tong[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
