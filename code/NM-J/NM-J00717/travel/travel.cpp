#include <bits/stdc++.h>
using namespace std;
int a,b,flag,nf;
string s,ss;
int of;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>b>>ss;
    if (a==b) cout<<1;
    else cout<<0;
    if (s[0]==ss[0] && s[1]==s[1]) cout<<1;
    else cout<<0;
    if (s[2]>='A' && s[2]<='C' &&ss[2]>='A' && ss[2]<='C') {
    	cout<<1;
    	nf=1;
	}

    if (s[2]>='D' && s[2]<='F' &&ss[2]>='D' && ss[2]<='F') {
        cout<<1;
        nf=1;
        of=1;
    }
	if (nf==0) cout<<0;
	if (of==1) cout<<1;
	if (of==0 &&(s[2]-'0')-(ss[2]-'0')==1 || (s[2]-'0')-(ss[2]-'0')==-1 && s[2]>='A' && s[2]<='C' &&ss[2]>='A' && ss[2]<='C')
	if (of==0 &&(s[2]-'0')-(ss[2]-'0')==1 || (s[2]-'0')-(ss[2]-'0')==-1 ) {
            cout<<1;
            flag=1;
        }

    if (flag==0) cout<<0;
	return 0;
}
