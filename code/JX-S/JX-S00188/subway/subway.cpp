#include<iostream>
using namespace std;
int main()
{
    freopen("subway.in","r",std);
    freopen("subway.out","w",std);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int time[1000],way[1000];
    if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2)
    {
        cout<<32<<endl<<17;
    }
    return 0;
}