#include<bits/stdc++.h>
using namespace std;
const int maxq=1e5+10;
int v[maxq],w[maxq],f[maxq];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int aa,bb;
    string a,b;
    cin>>aa>>a>>bb>>b;
    if(aa!=bb){
        cout<<"0000";
        return 0;
    }
    else{
        if(a[1]!=b[1]||a[0]!=b[0]){
            cout<<"1000";
            return 0;
        }
        else{
            if(a[2]=='A'){
                if(b[2]=='B')cout<<"1111";
                else if(b[2]=='C')cout<<"1110";
                else if(b[2]=='D')cout<<"1110";
                else cout<<"1100";
            }
            else if(a[2]=='B'){
                if(b[2]=='A')cout<<"1111";
                else if(b[2]=='C')cout<<"1111";
                else if(b[2]=='D')cout<<"1110";

                else cout<<"1100";
            }
            else if(a[2]=='C'){
                if(b[2]=='A')cout<<"1110";
                else if(b[2]=='B')cout<<"1111";
                else if(b[2]=='D')cout<<"1100";

                else cout<<"1100";
            }
            else if(a[2]=='D'){
                if(b[2]=='A')cout<<"1100";
                else if(b[2]=='B')cout<<"1100";
                else if(b[2]=='C')cout<<"1100";
                else cout<<"1111";
            }
            else if(a[2]=='F'){
                if(b[2]=='A')cout<<"1100";
                else if(b[2]=='B')cout<<"1100";
                else if(b[2]=='C')cout<<"1100";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
