#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie();
    cout.tie();
    string a="",b="",c="",d="";
    int q=0,w=0,e=0,r=0;
    cin>>a>>b>>c>>d;
    if(a==c){
    	q++;
	}
	if(q==0){
		cout<<q<<w<<e<<r;
    	return 0;
	}
	if(b[1]==d[1]){
		w++;
	}
	if(w==0){
		cout<<q<<w<<e<<r;
    	return 0;
	}
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))){
    	e++;
	}
	if(e==0){
		cout<<q<<w<<e<<r;
    	return 0;
	}
	if(b[2]==d[2]-1||b[2]==d[2]+1){
    	r++;
	}
	cout<<q<<w<<e<<r;
    return 0;
}

