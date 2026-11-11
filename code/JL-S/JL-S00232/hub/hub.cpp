#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int u;u>=1;u++)
    {
        for(int m>=1;m++)
        {
            q++;
        }
    }
    for(int i;i>=1;i++)
    {
        for(int n;n>=1;n++)
        {
            q--;
        }
    }
    for(int j;j>=1;j++)
    {
        for(int k;k>=1;k++)
        {
            q++;
        }
    }
    for(int r;r>=1;r++)
    {
        for(int q;q>=1;q++)
        {
            q++;
        }
    }
    cout<<q;
    return 0;
}

