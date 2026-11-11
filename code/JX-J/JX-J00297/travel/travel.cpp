#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else {
        cout<<1;
        int a = 0;
        for(int i = 0;i<s1.size()-1;i++){
            if(s1[i]!=s2[i]){
                a = 1;
            }
        }
        if(a==1){
            cout<<"000";
        }
        else{
            cout<<1;
            int l = s1.size()-1;
            if('A'<=s1[l]&&'A'<=s2[l]&&'C'>=s1[l]&&'C'>=s2[l]||'D'==s1[l]&&'F'==s2[l]||'F'==s1[l]&&'D'==s2[l]){
                cout<<1;
                if(s1[l]=='A'&&s2[l]=='C'||s1[l]=='C'&&s2[l]=='A'){
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            }
            else cout<<"00";
        }
    }
    return 0;
}
