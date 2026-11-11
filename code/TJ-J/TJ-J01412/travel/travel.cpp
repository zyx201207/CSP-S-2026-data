#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int b1[10], t1[10], b2[10], t2[10];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for (int i = 0; i < c1.size(); i++)
    {
        b1[i] = c1[i] - '0';
    }
    for (int i = 0; i < c2.size(); i++)
    {
        b2[i] = c2[i] - '0';
    }
    bool flag = false;
    for (int i = 0; i < c1.size(); i++)
    {
        if (b1[i] == b2[i])flag = true;
        else flag = false;
    }
    if (flag)
    {
    	cout << 1;
    	for (int i = 0; i < s1.size() - 1; i++)
    	{
        	t1[i] = s1[i] - '0';
    	}
    	for (int i = 0; i < s2.size() - 1; i++)
    	{
        	t2[i] = s2[i] - '0';
    	}
    	bool flog = false;
    	for (int i = 0; i < s1.size() - 1; i++)
    	{
        	if (t1[i] == t2[i]) flog = true;
        	else flog = false;
    	}
    	if (flog)
    	{
        	cout << 1;
        	if ((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C'))
        	{
            	cout << 1;
            	if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'D' && s2[2] == 'F')
            	{
                	cout << 1;
            	}
            	else if(s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'F' && s2[2] == 'D')
            	{
                	cout << 1;
            	}
            	else cout << 0;
        	}
        	else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))
        	{
            	cout << 1;
        	}
        	else cout << 0 << 0;
    	}
    	else cout << 0 << 0 << 0;
	}
    else cout << 0 << 0 << 0 << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
