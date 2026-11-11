/* construct : OCT 31'26 */
#include	<bits/stdc++.h>
#define		int		long long
using namespace std;

signed main (void)
{
    system ("g++ std.cpp -o std");
    system ("g++ tst.cpp -o tst");
    for (int i = 1; ; i++)
    {
        cout << "Test Case #" << i << " : ";
        system ("python3 generator.py > test.in");
        system ("./std < test.in > std.out");
        system ("./tst < test.in > tst.out");
        if (system ("cmp std.out tst.out"))
        {
            puts ("WA");
            return 1;
        }
        puts ("AC");
    }
    return 0;
}
