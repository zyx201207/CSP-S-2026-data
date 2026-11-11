#include <bits/stdc++.h>

using namespace std;
int n;
char a[5];
int cnt=0;

int main()
{
cin>>n;
if(n==1)
{
   cout<<"0";
}
for(int i=2;i<=n;i++)
{
   cin>>a[i];
}
for(int i=2;i<=n;i++)
{
 if(a[i]!=a[i]*2)
 {
    cnt++;
 }
}
cout<<cnt;
return 0;

}
