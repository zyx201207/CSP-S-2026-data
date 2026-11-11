#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q=0,w=0,e=0,r=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        q=1;
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            w=1;
            char c=s1[2],d=s2[2];
            if(c=='A' && d=='B' || c=='A' || d=='C' || c=='B' && d=='C'){
                e=1;
                if(c=='A' && d=='B' || d=='B' && c=='C') r=1;
            }
            else if(c-2==d ||d-2==c){
                e=1;
                r=1;
            }
        }
    }
    cout<<q<<w<<e<<r;
    return 0;
}
