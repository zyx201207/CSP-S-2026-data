#include<iostream>
#include<cstring>
using namespace std;
string s1 , s2;
int main()
{
    freopen("travel2.in" , "r" , stdin);
    freopen("travel2.ans" , "w" , stdout);
    int m , n;
    cin >> m;
    cin >> s1;
    cin >> n;
    cin >> s2;
    cout << m  <<" "<<n <<endl;
    if(m == n)
    {
        cout<< "1";
        int x1 = (s1[0] - '0')*10 +(s1[1] - '0');
        char x2 = s1[2];
        int y1 = (s2[0] - '0')*10 +(s2[1] - '0');
        char y2 = s2[2];
        if(x1 == y1 )
        {
            cout << "1";
            if((x2 <= 'C' && y2 <= 'C' && x2 != y2) || (x2 >= 'D' && y2 >= 'D'&& x2 != y2))
            {
                cout << "1";
                if(x2-y2 == 1 || y2 - x2 ==1)
                    cout <<"1";
                else
                    cout << "0";
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
}
