#include<bits/stdc++.h>
using namespace std;
string y,a,l,r;
long long n,x[200005],ans = 0,minn,sum = 0,lal = 0,lar = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> x[i] >> y;
        ans += x[i];
        a += y;
    }
    int i = 0,j = n-1;
    l = a[0],r = a[n-1];
    lal = x[i] ,lar = x[j];
    ans = ans /2;
    while(i <= j)
    {
        if(l == r)
        {
            if(lal > lar)
            {
                ans -= lar;
                lal = lal - lar;
                lar = 0;
                j--;
                r= a[j];
            }
            else if(lal < lar)
            {
                ans -= lal;
                lar = lar - lal;
                lal = 0;
                i++;
                l = a[i];
            }
            else{
                ans -=lal;
                i++;
                j--;
                l = a[i];
                r = a[j];
                lal = x[i];
                lar = x[j];
            }
        }
        else{
            i++;
            j--;
            if(lal > lar)
            {
                lal = lal - lar;
                lar = 0;
                r = a[j];
                l = a[i];
            }
            else if(lar > lal){
                lar =  lar - lal;
                lal =0;
            }
            else
                {
                lal =lar= 0;
                l = a[i];
                r = a[j];
                lar = x[j];
                lal = x[i];
            }
        }
    }
    cout << ans;
    return 0;
}
