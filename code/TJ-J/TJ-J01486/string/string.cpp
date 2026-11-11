#include <iostream>
#include <cstdio>
using namespace std;
struct Sagment
{
    int count;
    char ch;
};
int maxN = 2*100000 + 1;
Sagment sag1[maxN];
int main()
{
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/string/string,in","r",stdin);
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/string/string,out","w",stdout);
    int n;
    cin >> n;
    string s = "";
    int ans = 0;
    int len = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> sag1[i].count >> sag1[i].ch;
        for(int j = 0;j < count;j++)
        {
            s+=ch;
        }
        len += sag1[i].count;
    }
    int ans = 0;
    int sagi = 0,chipos = 0, sagj = n - 1, chjpos = len - 1;
    int convertCount = 0;
    while(true)
    {
        convertCount = min(min(sag,), );
        chi += sag[sagi].count;
        if(chi > len / 2) chi = len / 2;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
