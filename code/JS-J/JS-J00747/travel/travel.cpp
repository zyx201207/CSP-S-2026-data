#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s1,s2;
    string c1,c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2) cout<<"0000";
    else{
        cout<<'1';
        int i=0,cnt1=0,cnt2=0;
        while(c1[i]>='0'&&c1[i]<='9'){
            cnt1+=c1[i]-'0';
            cnt1*=10;
            i++;
        }
        i=0;
        while(c2[i]>='0'&&c2[i]<='9'){
            cnt2+=c2[i]-'0';
            cnt2*=10;
            i++;
        }
        if(cnt1!=cnt2) cout<<"000";
        else{
            cout<<'1';
            if((c1[i]>='A'&&c1[i]<='C'&&c2[i]>='A'&&c2[i]<='C')||((c1[i]=='D'||c1[i]=='F')&&(c2[i]=='D'||c2[i]=='F'))){
                cout<<'1';
                if(abs(int(c2[i])-int(c1[i]))<=1) cout<<'1';
                else cout<<0;
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}
