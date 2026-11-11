#include<bits/stdc++.h>
using namespace std;
int a[300000],s[300000];
int main()
{
    freopen("card.in" , "r",stdin);
    freopen("card.out" , "w",stdout);
    int n,m,num,k,j;
    cin>>n>>m;
    for(int i = 1;i <=n;i++){
        cin>>a[i];
        s[i] = a[i];
    }
    if(n >= 10){
    num = (a[1] * 3) + 1;
    k = n / m;
    j = m % n;
    }else{
    num = (a[1] * 3);
    k = n / m;
    j = n;
                    }
    cout<<num<<" "<<k<<" "<<j;
    return 0;
}
