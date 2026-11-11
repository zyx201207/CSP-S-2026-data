#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x[100],n[100];
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << "1";
    }
    else{
        cout << "0";
    }
    for(int i = 0;i <= b.length();i++)
    {
        cin >> x[i];
    }
    for(int j = 0;j <= d.length();j++)
    {
        cin >> n[j];
    }
    if(x[0] == n[0] && x[1] == n[1])
    {
        cout << "1";
    }
    else{
        cout << "0";
    }

        return 0;
}
