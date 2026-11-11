#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n,m;
int a,b;
char x,y;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> n >> a>>x;
    cin >> m >> b>>y;
    cout << (int)(n == m);
    cout << (int)(n==m&&a==b);
    cout << (int)((n==m&&a==b)&&(((int)x<(int)'D'&&(int)y<(int)'D')||((int)x>(int)'C'&&(int)y>(int)'C')));
    cout << (int)((n==m&&a==b)&&(((int)x<(int)'D'&&(int)y<(int)'D')||((int)x>(int)'C'&&(int)y>(int)'C'))&&abs((int)y-(int)x) < 2);
    return 0;
}
