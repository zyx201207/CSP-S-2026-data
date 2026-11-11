#include<bits/stdc++.h>
using namespace std;
string ac,bc,ah,bh;
int i,j,k,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ac>>ah>>bc>>bh;
	i=j=k=l=0;
	if(ac[0]==bc[0]&&ac[1]==bc[1]){
		i=1;
	}if(ah[0]==bh[0]&&ah[1]==bh[1]&&i==1){
		j=1;
	}if((ah[2]>='D'&&bh[2]>='D')||(ah[2]<='C'&&bh[2]<='C')){
		if(j==1){
			k=1;
		}
	}if(abs(int(ah[2]-bh[2]))==1&&((ah[2]!='C'&&bh[2]!='D')||(ah[2]!='D'&&bh[2]!='C'))){
		if(k==1){
			l=1;
		}
	}cout<<i<<j<<k<<l;
	return 0;
}
