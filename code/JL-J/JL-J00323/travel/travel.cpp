#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.cpp","r",stdin)
    freopen("travel.cpp","w" ,stdout)
    int c1;
    int s1;
    string c2;
    string s2;
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1==s1 && c1!=01 && c1!=16 && s1!=01 && s1!=16)
        cout << 1;
    else
        cout << 0;
    cout << 110;
    fclose(stdin)
    flclose(stdcout)
    return 0;
}
