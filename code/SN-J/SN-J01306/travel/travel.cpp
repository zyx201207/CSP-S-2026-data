#include<bits/stdc++.h>
using namespace std;
int ac,bc;
string ap,bp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>ac>>ap>>bc>>bp;
    cout<<(ac == bc ? "1" : "0");
	cout<<(ac == bc && ap[0] == bp[0] && ap[1] == bp[1] ? "1" : "0");
	cout<<(ac == bc && ap[0] == bp[0] && ap[1] == bp[1] && ((ap[2]<'D' && bp[2]<'D') || (ap[2]>'C' && bp[2]>'C'))? "1" : "0");
	cout<<(ac == bc && ap[0] == bp[0] && ap[1] == bp[1] && abs(ap[2] - bp[2])==1 && !(ap[2] == 'C' && bp[2] == 'D') && !(ap[2] == 'D' && bp[2] == 'C')? "1" : "0");
}

