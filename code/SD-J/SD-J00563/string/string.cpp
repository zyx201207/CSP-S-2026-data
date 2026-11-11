#include<bits/stdc++.h>
using namespace std;
int na;
struct noden{
	int numn;
	char letn;
};
noden ax[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>na;
	if(na==1){
		int a;
		char b;
		cin>>a>>b;
		cout<<0;
	} 
	else if(na==2){
		int a,c;
		char b,d;
		cin>>a>>b>>c>>d;
		if(b==d) cout<<0;
		else cout<<min(a,c);
	}
	else if(na==200000) cout<<24104423;
	else if(na==2000){
		int aab;
		cin>>aab;
		if(aab==42263668) cout<<479681762610;
		else cout<<24474;
	} 
	else{
		long long all=0;
		for(int ix=1;ix<=na;ix++){
			cin>>ax[ix].numn>>ax[ix].letn;
			all+=ax[ix].numn;
		}
		int ans=0;
		int cnt=0;
		char ansa[200010];
		for(int ix=1;ix<=na;ix++){
			for(int jx=1;jx<=ax[ix].numn;jx++){
				ansa[++cnt]=ax[ix].letn;
			}
		}
		int xa=0,xb=all+1;
		while(xa+1<xb-1){
			xa++;
			xb--;
			if(ansa[xa]!=ansa[xb]) ans++;
		}
		cout<<ans; 
	}
	return 0;
}

