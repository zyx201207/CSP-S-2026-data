#include<bits/stdc++.h>
using namespace std;

string c1;
string s1;
string c2;
string s2;    
string a1 = "";
string a2 = "";

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    a1 += s1[0];
    a1 += s1[1];
    a2 += s2[0];
    a2 += s2[1];
    if(c1 != c2)
    {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if(a1 != a2)
    {
        cout << 1 << 0 << 0 << 0;
        return 0;
    }
    if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'F'))
    {
        cout << 1 << 1 << 0 << 0;
        return 0;
    }
    else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
    {
        cout << 1 << 1 << 0 << 0;
    }
    int b1 = int(s1[2]);
    int b2 = int(s2[2]);
    if(abs(b1 - b2) == 1)
    {
        cout << 1 << 1 << 1 << 1;
    }
    else
    {
    	cout << 1 << 1 << 1 << 0;
	}
    return 0;
}
