#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f,g,h,j,k,l,m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    j='A';
    k='B';
    l='C';
    m='D';
    n='F';
    e=c[0]+c[1];
    f=d[0]+d[1];
    g=c[2];
    h=d[2];
    if(a==b) cout<<1;
    else {
		cout<<0<<0<<0<<0;
		return 0;
	}
    if(e==f) cout<<1;
    else{
		cout<<0<<0<<0;
		return 0;
    }
    if(g==j&&h==k)
        cout<<1;
    else if(g==k&&h==j)
        cout<<1;
    else if(g==j&&h==l)
        cout<<1;
    else if(g==l&&h==j)
        cout<<1;
    else if(g==k&&h==l)
        cout<<1;
    else if(g==l&&h==k)
        cout<<1;
    else if(g==m&&h==n)
        cout<<1;
    else if(g==n&&h==m)
        cout<<1;
    else{
		cout<<0<<0;
		return 0;
    }
    if(g==j&&h==l)
        cout<<0;
    else if(g==l&&h==j)
        cout<<0;
    else{
		cout<<1;
	}
	return 0;
}
