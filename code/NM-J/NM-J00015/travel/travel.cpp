#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    //cout<<s1[3]<<" "<<s2[3]<<"\n";
    //int f1 = 0;
    //int f2 = 0;
    //if (c1 == "01" || c1 == "16"){
    //    f1 = 1;
    //}
    //if (c2 == "01" || c2 == "16"){
    //    f2 = 1;
    //}
    if (c1 == c2){
        ans += "1";
        int a1 = (s1[0]-'0')+(s1[1]-'0')*10;
        int a2 = (s2[0]-'0')+(s2[1]-'0')*10;
        if (a1 == a2){
            ans += "1";
            int b1 = s1[2]-'A';
            int b2 = s2[2]-'A';
            int bb1 = 0;
            int bb2 = 0;
            if (b1>3) bb1 = 1;
            if (b2>3) bb2 = 1;
            if (bb1 == bb2){
                ans += "1";
                if (abs(b1-b2) == 1){
                    ans += "1";
                }
                else {
                    cout<<"1110"<<"\n";
                    return 0;
                }
            }
            else {
                cout<<"1100"<<"\n";
                return 0;
            }
        }
        else {
            cout<<"1000"<<"\n";
            return 0;
        }
    }
    else {
        cout<<"0000"<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
    return 0;
}
