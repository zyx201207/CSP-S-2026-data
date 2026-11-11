#include<bits/stdc++.h>

#define ll long long

using namespace std;

int rc,rs,xc,xs;
char rl,xl;

char in1,in2,in3;

bool res=true;

int getpair(){

	cin>>in1>>in2;
	return int(in1-48)*10 + int(in2-48);

}

int main(){

	// freopen("travel5.in","r+",stdin); //its a TEST

	freopen("travel.in","r",stdin); //enbale it when upload
	freopen("travel.out","w",stdout);  

	//--input--
	
	rc=getpair();
	rs=getpair();
	cin>>rl;

	xc=getpair();
	xs=getpair();
	cin>>xl;

	//--solve--

	res&=(rc==xc);
	cout<<res;

	res&=(rs==xs);
	cout<<res;

	bool isDFside=(
		(rl=='D' && xl=='F')||
		(rl=='F' && xl=='D')
	);

	res&=(
		isDFside ||
		(
			'A'<=rl && rl<='C' &&
			'A'<=xl && xl<='C' 
		)
	);
	cout<<res;

	res&=(
		isDFside ||
		abs(rl-xl)==1
	);
	cout<<res;

	cout<<'\n';

	return 0;
}