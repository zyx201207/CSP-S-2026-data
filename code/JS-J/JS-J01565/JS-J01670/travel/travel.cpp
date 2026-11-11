#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
string ans="0000";
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        ans[0]='1';
        if(s1.substr(0,2)==s2.substr(0,2)){
            ans[1]='1';
            if(s1[2]>='A'&&s1[2]<='C'){
                if(s2[2]>='A'&&s2[2]<='C'){
                    ans[2]='1';
                }else{
                    cout << ans;
                    return 0;
                }
            }else if(s1[2]>='D'&&s1[2]<='F'){
                if(s2[2]>='D'&&s2[2]<='F'){
                    ans[2]='1';
                }else{
                    cout << ans;
                    return 0;
                }
            }
            if(char(s1[2]+1)==s2[2]||char(s2[2]+1)==s1[2]){
                ans[3]='1';
                cout << ans;
                return 0;
            }else{
                cout << ans;
                return 0;
            }
        }else{
            cout << ans;
            return 0;
        }
    }else{
        cout << ans;
        return 0;
    }
}