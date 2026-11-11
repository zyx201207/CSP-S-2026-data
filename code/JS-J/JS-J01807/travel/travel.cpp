#include <iostream>
using namespace std;

bool check(char ch)
{
    if(ch >= 'A' && ch <= 'C')
        return true;//true == left
    return false;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag = true;
    cin>>c1>>s1>>c2>>s2;
    cout<<(flag && c1 == c2);
    flag = (c1 == c2);
    cout<<(flag && s1[0] == s2[0] && s1[1] == s2[1]);
    flag = (flag && s1[0] == s2[0] && s1[1] == s2[1]);
    cout<<(flag && (check(s1[2]) == check(s2[2])));
    flag = (flag && (check(s1[2]) == check(s2[2])));
    cout<<(flag && (abs(s1[2] - s2[2])) == 1);
    return 0;
}
