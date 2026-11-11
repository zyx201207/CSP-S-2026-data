#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],m;
string ma(int i)
{
    long long num = 1;
    string s = "";
    while(i > 0)
    {
         if(num%2 == 0) s+='0';
         else s+='1';
         num = num/2;

    }
    return s;
}
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    cout << ma(5);
    return 0;
}
