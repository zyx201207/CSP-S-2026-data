#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.ans","w",stdout);
    freopen("migrate.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<b;i++)
    cout<<rand()/10%7+rand()%10<<endl;
    cout<<rand()/10%5+1;
    return 0;
}
