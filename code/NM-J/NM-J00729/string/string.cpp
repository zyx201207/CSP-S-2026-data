#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

     char r;
     int n,m=0,k=0,f;
     int a[100050],b[100050];
     cin >> n;
     for(int i = 1;i < n;i++){
        cin >> f >> r;
        for(int j = 1;j < f;j++){
                a[k] = r;
                a++;
        }
     }
     for(int i = 1;i < k;i++){
         b[k - i] = a[i];
     }
     for(int i = 0;i <= n;i++){
         if(b[i] != a[i]){
            m++;
         }
         cout << m;
     }
    return 0;
}
