#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
int a;
int zh;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    IOS;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    cout<<s;
    for(int i=0;i<(s.size()+1)/2;i++){
        if(s[i]!=s[s.size()-i-1]) zh++;
    }
    cout<<zh;



    return 0;
}
