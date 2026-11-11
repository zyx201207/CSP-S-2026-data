#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a,b;
    string c,d;
    cin >> a >> c >> b >> d;
    string ans="";
    bool k=(a==b);
    if(k){
        k=(c.substr(0,2)==d.substr(0,2));
        if(k){
            int x=(c[2]-'A'+1);
            int y=(d[2]-'A'+1);
            if((x<=3&&y<=3)||(x>=4&&y>=4)){
                if(abs(x-y)==1){
                    ans="1111";
                }
                else{
                    ans="1110";
                }
            }
            else{
                ans="1100";
            }
        }
        else{
            ans="1000";
        }
    }
    else{
        ans="0000";
    }
    cout << ans;
    return 0;
}
