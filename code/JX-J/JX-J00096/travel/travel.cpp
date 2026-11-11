#include <iostream>
using namespace std;
string rzw,xzw;
int rcx,xcx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int yq;
    cin >> rcx >> rzw >> xcx >> xzw;
    //che xiang
    if(rcx==xcx)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    //pai
    if(rzw[0] == xzw[0] && rzw[1] == xzw[1])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    //pai+ce
    if(rzw[0] == xzw[0] && rzw[1] == xzw[1])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    //yq
    if(yq%2==0 || yq%3==0)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0;
}
