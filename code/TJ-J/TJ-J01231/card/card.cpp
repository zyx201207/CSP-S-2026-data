#include<iostream>
#include<random>
using namespace std;
int a[10000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
int m,n;
cin>>m>>n;
for (int i=0;i<=m;i++)
{
    a[i]=n;
}
cout <<m<<n<<n;
return 0;
 }
