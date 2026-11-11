#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[500005];
    int b[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    string s;
    bool flag=false;

    int x=n;
    int i=0;
    for(int g=1;g<=n;g++){
            i=g;
            int t=0;
    while(i<=n){

        if(flag==1||s[t]=='0'){
            s[t]=a[i]+'0';
            flag=0;
        }
        else {s+=a[i]+'0';t++;}
        for(int j=0;j<s.length()-1;j++)
        {
            if(s[j]==a[i]+'0'){
                s[j+1]='0';
                for(int y=j+1;y<s.length();y++)s[y]='0';
                t=j+1;
                flag=1;
            }
        }
         i++;

    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')break;
        b[s[i]-'0']++;
    }
    for(int j=0;j<s.length();j++)
    {
        s[j]='0';
    }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
}
