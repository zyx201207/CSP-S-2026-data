#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    int n,n1,w1,n2,w2,b,c,d,e;
    int a[55555555];
    cin>>n;
    cin>>n1>>w1;
    cin>>n2>>w2;
    a[55555555] = n1*w1 + n2 * w2;
    b = n1 + n2;
    c = b % 2;
    d = 0;
    e = 0;
    for(int i = 1;i<b;i++){
        if(a[i] = a[b - i])
            {
            e++;
        }
        else{
            d++;
        }
    }
    cout << d;
    return 0;
}
