#include<bits/stdc++.h> 
using namespace std;
int n,m,a[50005],tt[50005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		int t[500];
		for(int j=i;j<=n;j++){
			if(t[j]==0){
				v.push_back(a[j]);
				t[a[j]]=1;
			}
			else {
				v.clear();
				v.push_back(a[j]);
				for(int ii=1;ii<=500005;ii++){
					t[ii]=0;
				}
				t[a[j]]=1;
			}
		}
		for(int i=0;i<v.size();i++){
		     tt[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tt[i]<<" ";
	}
	return 0;
}
