#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    string a[5];
    string s[5]{"1111","1110","1100","1000","0000"}
    for(int i=0;i<=5;i++){
        cin>>a[i];
    }
    for(int i;i<=5;i++)
    {
        if(a[0]==a[2])
        {
           s[4]="no";
           if(1==1)
           {
               s[3]="no";
               if(1==1)
               {
                   s[2]="no";
                   if(a[i]+1==a[i+1] || a[i]-1==a[i+1])
                   {
                       s[1]="no";
                   }
               }
           }
        }
    }
    for(int i=4;i>=0;i--)
    {
        if(s[i]!="no")
        {
        cout<<s[i];
        return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
