#include <bits/stdc++.h>
using namespace std;

int a,b;
string a_,b_;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a_>>b>>b_;
    int ans = 0,ans1 = 0,ans2 = 0,ans3 = 0;
    if (a == b){
        ans = 1;
        if (a_[0] == b_[0]&&a_[1] == b_[1]){
            ans1 = 1;
            char aa = a_[2],bb = b_[2];
            if (aa<='C'&&bb<='C'){
                ans2 = 1;
                if (aa == 'B'||bb == 'B')
                    ans3 = 1;
            }
            if (aa>'C'&&bb>'C'){
                ans2 = 1;
                ans3 = 1;
            }
        }
    }
    cout<<ans<<ans1<<ans2<<ans3;
    return 0;
}
