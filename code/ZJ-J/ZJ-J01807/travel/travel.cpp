#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    bool ans[4] = {0,0,0,0};
    string s1,s2;
    int c1,c2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        ans[0]=1;
        if(s1[1] == s2[1]){
            ans[1] =1;
            if((s1[2]>'C'&&s2[2]>'C')){
                ans[2]=1;ans[3]=1;
            }
            else if(s1[2]<='C'&&s2[2] <='C'){
                ans[2]=1;
                if(s1[2]=='B' || s2[2] == 'B')
                    ans[3]=1;
            }   
        }
    }
    for(int i = 0 ; i < 4 ; i++)
        cout << ans[i];
    return 0;
}
