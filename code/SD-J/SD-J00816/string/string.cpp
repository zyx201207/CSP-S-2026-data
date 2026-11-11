#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n_j,a_j,h_j,l_j,r_j,cnt=0;
	cin>>n_j;
	string s_j="",b_j;
	for(int i_j=1;i_j<=n_j;i_j++){
		cin>>a_j;
		cin>>b_j;
		for(int j_j=1;j_j<=a_j;j_j++){
			s_j+=b_j;
		}
	}
	h_j=s_j.size();
	r_j=s_j.size()-1;
	for(l_j=0;l_j<h_j/2;l_j++){
		if(s_j[l_j]==s_j[r_j]);
		else cnt++;
		r_j--;
		
	}cout<<cnt;
	return 0;
}
