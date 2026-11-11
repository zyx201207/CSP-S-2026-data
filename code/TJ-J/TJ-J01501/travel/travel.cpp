#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r", stdin);
    freopen("travel.out","w", stdout);
	int c,s,r,t,z = 0000;
    cin >> c >> s >> r >> t;
    if(c == r)
	{
        z += 1000;
        if (s[0] = t[0] && s[1] = t[1]){
            z += 100;
            if(s[2] == 'A' && t[2] == 'B' || s[2] == 'A' && t[2] == 'C' || s[2] == 'B' && t[2] == 'C'|| s[2] == 'B' && t[2] == 'A' || s[2] == 'C' && t[2] == 'A' || s[2] == 'C' && t[2] == 'B'){
                z += 10;
                if (s[2] == 'A' && t[2] == 'B' || s[2] == 'B' && t[2] == 'A' || s[2] == 'B' && t[2] == 'C'||s[2] == 'C' && t[2] == 'B' || s[2] == 'D' && t[2] == 'E'|| s[2] == 'E' && t[2] == 'D'){
                	z += 1;
                }
            }
		}
	}
	cout << z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
