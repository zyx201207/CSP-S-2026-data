# include <bits/stdc++.h>
using namespace std;

string cr1,sr1,cr2,sr2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cr1>>sr1>>cr2>>sr2;
    if(cr1!=cr2){
        cout<<"0000";
        return 0;
    }
    if((sr1[0]!=sr2[0])||(sr1[1]!=sr2[1])) {
        cout<<"1000";
        return 0;
    }
    //shitongyipai
    if((sr1[2]>='A'&&sr1[2]<='C'&&sr2[2]>='A'&&sr2[2]<='C')||(sr1[2]>='D'&&sr1[2]<='F'&&sr2[2]>='D'&&sr2[2]<='F')){
        if(sr1[2]>='A'&&sr1[2]<='C'&&sr2[2]>='A'&&sr2[2]<='C'){
            if((sr1[2]+1==sr2[2])||(sr2[2]+1==sr1[2]))cout<<"1111";
            else cout<<"1110";
        }
        else{
            cout<<"1111";
        }
    }
    else cout<<"1100";
    return 0;
}
