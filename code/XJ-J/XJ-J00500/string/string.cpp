#include <bits/stdc++.h>

using namespace std;
char e[1024];

int main()
{

	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	
	bool aa=true;
	char c=' ',oc=' ';
	int a,b;
	long long d=0,od=0;
	cin >>a;
	cin >>b>>c;
	for(int i=1;i<a;i++){
		oc=c;
		cin >>b>>c;
		d+=b;
		if (c!=oc){
			if (d>=od){od=d;}
			d=0;
			aa=false;
			
		}
	}
	if (aa){
	cout <<0;
	return 0;
	}
	else{
	cout <<od;
	return 0;
	}
	return 0;

}