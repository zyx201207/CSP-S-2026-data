#include<bits/stdc++.h>
using namespace std;
int a[200000];
string s[200000];
int main()
{
    freopen("string.in" , "r",stdin);
    freopen("string.out" , "w" , stdout);
    int n,num = 0,j = 1,i,sum;
    cin>>n;
    i = n;
    for(int k = 1;k <= n;k++){
        cin>>a[k]>>s[k];
    }
    sum = a[n];
    while( i !=(n / 2) + 1 && j != (n / 2) + 1){
        if(s[i] != s[j] || a[i] != a[j]){
            if(a[i] > a[j]){
                num = num + a[i] - a[j];
                a[j] = 0;
                a[i] = a[i] - a[j];
            }else{
                num = num + a[j];
                a[j] = a[j] - a[i];
                a[i] = 0;
            }
        }else if(s[i] != s[j] && a[i] == a[j]){
            num = num + a[i];
            a[i] = 0;
            a[j] = 0;
        }else{
            a[j] = a[i] = 0;
        }
        if(a[i] == 0){
            i--;
        }
        if(a[j] == 0){
            j++;
        }
    }

    cout<<num;
    return 0;
}
