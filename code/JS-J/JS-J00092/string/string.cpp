#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,a[N],pre[N],las[N];
char c[N];

int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i] >> c[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i=n;i>=1;i--) las[i] = las[i+1] + a[i];
    int i=1,j=n,ans=0;
    while(i<j)
    {
        if(pre[i] > las[j])
        {
            
            if(c[i] != c[j]) ans += a[j];
            j--;
        }
        else if(pre[i] < las[j])
        {
            i++;
        }
        else
        {
            i++;j--;
        }
    }
    // cout << i << j << ans << endl;
    if(j+1==i) cout << ans;
    else 
    {
        int mid = pre[n] / 2;
        if(pre[n] % 2 == 1) mid ++ ;
        // cout << mid << endl;
        if(pre[i]-mid) ans += pre[i] - mid;
        cout << ans;
    }

    return 0;
}