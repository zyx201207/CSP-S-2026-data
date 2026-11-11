#include<bits/stdc++.h>
using namespace std;
const int N_j=2e5+2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n_j,m_j,a_j[N_j],maxn_j=-1;
	cin>>n_j>>m_j;
	for(int i_j=1;i_j<=n_j;i_j++){
		cin>>a_j[i_j];
	}
	for(int k_j=1;k_j<=m_j;k_j++){
		for(int i_j=1;i_j<=n_j;i_j++){
			if(a_j[i_j]==-1)continue;
			for(int j_j=1;j_j<=n_j;j_j++){
				if(a_j[j_j]==-1)continue;
				if(maxn_j<a_j[i_j] and a_j[j_j]){
					maxn_j=a_j[i_j] and a_j[j_j];
					a_j[j_j]=-1;
					a_j[i_j]=-1;
				}	
			}
		}
	}cout<<maxn_j;
	return 0; 
} 
