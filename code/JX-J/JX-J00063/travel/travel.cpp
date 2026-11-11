#include <bits/stdc++.h>
using namespace std;
long long A[4] = {0,0,0,0};
bool B[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        A[0] = 1;
        B[0] = true;
    }
    if(s1[0] + s1[1] == s2[0] + s2[1] && B[0])
    {
        A[1] = 1;
        B[1] = true;
    }
    if((s2[2] == 'D' && s1[2] == 'F' && B[1]) || (s1[2] == 'D' && s2[2] == 'F' && B[1]) || (s1[2] <= 'C' && s2[2] <= 'C' && B[1]))
    {
        A[2] = 1;
        B[2] = true;
    }
    if(max(s1[2],s2[2]) - min(s1[2],s2[2]) == 1 && B[2] || (s1[2] == 'D' && s2[2] == 'F' && B[2]) || (s2[2] == 'D' && s1[2] == 'F' && B[2]))
    {
        A[3] = 1;
    }
    for(long long i = 0;i < 4;i++)
    {
        cout << A[i];
    }
    cout << endl;
    return 0;
}
