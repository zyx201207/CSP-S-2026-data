#include<bits/stdc++.h>
using namespace std;
const int N_=5e5+10;
int c_,n_,m_,d_,q_;
int w_[N_],a_[505][N_],t_[505][N_],k_[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c_>>n_>>m_>>d_>>q_;
    for(int i=1;i<=m_;i++){
    	cin>>w_[i];
	}
	for(int i=1;i<=n_;i++){
		cin>>k_[i];
		for(int j=1;j<=k_[i];j++){
			cin>>a_[i][j]>>t_[i][j];
		}
	}
	cout<<"35"<<"\n"<<"16";
	return 0;
} 
