#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int r1=s1[0]+s1[1]-2*'0',r2=s2[0]+s2[1]-2*'0';
    char l1=s1[2],l2=s2[2];
    bool f=(c1==c2);
    cout << f << (f&&(r1==r2));
    bool f1=f&&(r1==r2)&&!((l1-'A'<3)^(l2-'A'<3));
    cout << f1 << (f1&&(abs(int(l1)-int(l2))==1));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
