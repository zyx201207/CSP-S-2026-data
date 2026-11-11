#include <bits/stdc++.h>

using namespace std;

int main()
{
   int m,n;
   cin>>n>>m;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   sort(a,a+n);
   int b=a[n];
   if(m==1){
    cout<<a[n];
    return 0;
   }
   for(int i=n;i>=m;i--){
    b=(b||a[i]);
   }
   cout<<b;
    return 0;
}
