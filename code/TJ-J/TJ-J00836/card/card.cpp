#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in",'r',stdin);
//	freopen("card.out",'w',stdout);
	int n, m;
	cin>>n>>m;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i]; 
	}
	vector<int> ans(m+1);
	for(int i=1;i<=n;i++){
		vector<int> gh(m+1);
		int temp[500002];
		int k=i;
		for(int j=i;j<=n;j++){
			if(gh[v[j]]==0){
				temp[k]=v[j];
				gh[v[j]]=1;
			}
			else{
				int l;
				for(l=k;l>=i;l--){
					if(temp[l]==v[j]){
						break;
					}
					gh[temp[l]]=0; 
				}
				k=l;
			}
			k++;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=gh[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
