#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

int read()
{
    int x=0;
    char cc;
    while(!('0'<=cc&&cc<='9')) cc=getchar();
    while('0'<=cc&&cc<='9')
    {
        x=x*10+(cc-'0');
        cc=getchar();
    }
    return x;
}

signed main()
{

    cout<<read()<<" "<<read();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
