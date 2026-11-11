#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check(char A,char B){
	if(A=='A') return (B=='B')||(B=='C');
	if(A=='B') return (B=='A')||(B=='C');
	if(A=='C') return (B=='B')||(B=='A');
	if(A=='D') return B=='F';
	return B=='D';
}
bool pd(char A,char B){
	if(A=='A') return B=='B';
	if(A=='B') return (B=='A')||(B=='C');
	if(A=='C') return B=='B';
	if(A=='D') return B=='F';
	return B=='D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&check(b[2],d[2])) cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&pd(b[2],d[2])) cout<<1;
    else cout<<0;
}