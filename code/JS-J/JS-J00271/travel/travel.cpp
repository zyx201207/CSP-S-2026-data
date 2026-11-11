#include <bits/stdc++.h>
#include <string>
#define int long long
#define pii pair<int,int>
const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1;
int ans[4];
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1="",s1="",c2="",s2="";
    cin >> c1 >> s1 >> c2 >> s2;
    string r1,r2;
    char l1,l2;
    r1=s1.substr(0,2);
    r2=s2.substr(0,2);
    l1=s1[2];
    l2=s2[2];
    if(l1=='F'){
        l1='E';
    }if(l2=='F'){
        l2='E';
    }
    if(c1==c2){
        ans[0]=1;
        if(r1==r2){
            ans[1]=1;
            if((l1<='C' && l2<='C') || (l1>'C' && l2>'C')){
                ans[2]=1;
                if(abs(l1-l2)==1){
                    ans[3]=1;
                }
            }
        }
    }
    for(auto a:ans){
        cout << a;
    }
}
