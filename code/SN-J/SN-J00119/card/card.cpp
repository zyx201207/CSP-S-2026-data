#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v(m);
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int id=0;
	for(int i=0;i<n;i++){
		vector<int>f;
		for(int j=i;j<n;j++){
			f.push_back(a[j]);
			id++;
			int index;
			for(int k=id-2;k>=0;k--){
				if(f[k]==a[j]){
					index=k;
					break;
				}
			}
			for(int k=index;k<id-k-1;k++){
				f[k]=0;
			}
			for(int i=0;i<id;i++){
				v[f[i]]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<v[i];
	}
	return 0;
}

