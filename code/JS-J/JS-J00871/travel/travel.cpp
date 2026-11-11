#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ans1=0;
    int ans2=0;
    int ans3=0;
    int ans4=0;
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[1]==c2[1]&&c1[0]==c2[0])
        ans1==1;
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        ans2==1;
    if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C')
    {
        ans3==1;
        if(s1[2]=='B'||s2[2]=='B')
            ans4==1;
        else
            ans4==0;
    }
    if('D'<=s1[2]<='F'&&'D'<=s2[2]<='F')
    {
        ans3==1;
        ans4==1;
    }
    cout << ans1 << ans2 << ans3 << ans4 <<endl;





    return 0;
}

