#include<bits/stdc++.h>
using namespace std;
string awm;
int chang,ans;
int main(){
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int nn1;
	cin>>nn1;
	for(int ii1=1;ii1<=nn1;ii1++){
		int aa1;char cc1;
		cin>>aa1>>cc1;
		for(int jj1=1;jj1<=aa1;jj1++){
			awm+=cc1;
		}
		chang+=aa1;
	}
	for(int ii1=0;ii1<chang/2;ii1++){
		if(awm[ii1]!=awm[chang-ii1-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

