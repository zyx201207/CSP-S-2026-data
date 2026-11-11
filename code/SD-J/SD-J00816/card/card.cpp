#include<bits/stdc++.h>
using namespace std;
const int N_j=5e5+2;
const int M_j=3e5+2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n_j,m_j,a_j[N_j],cnt_j[M_j],ans_j[N_j],ch_j[N_j],hl_j=0;
	cin>>n_j>>m_j;
	for(int i_j=1;i_j<=n_j;i_j++){
		cin>>a_j[i_j];
	}
	for(int i_j=1;i_j<=n_j;i_j++){
		for(int j_j=i_j;j_j<=n_j;j_j++){
			for(int k_j=1;;k_j++){
				for(int h_j=1;;h_j++){
					if(cnt_j[h_j]!=ch_j[k_j]){
						cnt_j[k_j]=ch_j[k_j];
					}
				}
			}
			if(cnt_j[j_j]=m_j){
				hl_j++;
			}
		}
		cout<<hl_j<<endl;
		hl_j=0;
	}
	return 0;
}
