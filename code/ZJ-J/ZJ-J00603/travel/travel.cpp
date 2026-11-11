#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;

signed main(void){
	IOS;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
                cout<<"11\n";
            }
            else if(s1[2]!='F'&&s1[2]!='D'&&s2[2]!='D'&&s2[2]!='F'){
                cout<<"1";
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
                    cout<<1<<endl;
                }else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
                    cout<<1<<endl;
                }else cout<<0<<endl;
            }else{
                cout<<"00\n";
            }
        }
        else cout<<"000\n";
    }
    else cout<<"0000\n";
	return 0;
}
