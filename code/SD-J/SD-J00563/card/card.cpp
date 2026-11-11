#include<bits/stdc++.h>
using namespace std;
int na,ma,cnta=0;
int ax[500010];
int nowa[500010];
int alla[300010];
int enda=0;
struct nodea{
	bool zla;
	int numn;
}; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>na>>ma;
	for(int ix=1;ix<=na;ix++){
		cin>>ax[ix];
	}
	for(int ix=1;ix<=na;ix++){
		nodea leta[300010];
		int cnta=0;
		for(int jx=ix;jx<=na;jx++){
			if(leta[jx].zla!=0){
				for(int kx=leta[jx].numn+1;kx<=cnta;kx++){
					leta[kx].zla==0;
				}
				cnta=leta[jx].numn-1;
			} 
			leta[jx].zla=1;
			leta[jx].numn=cnta+1;
			nowa[++cnta]=ax[jx];
		}
		for(int jx=1;jx<=cnta;jx++) alla[jx]++;
		enda=max(enda,cnta);
	}
	for(int ix=1;ix<=enda;ix++) if(alla[ix]!=0) cout<<alla[ix]<<' '; 
	return 0;
}

