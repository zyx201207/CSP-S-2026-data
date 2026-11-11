#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,m;
    string s,a;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
           cin>>m>>c;
           for(int j=1;j<=m;j++)
                s+=c;

    }
    s+=c;
    int sum=0;
    for(int i=1,j=s.size();i<=s.size()/2;i++,j--)
    {
        if(s[i]!=s[j])
            sum++;
    }
    cout<<sum;




    return 0;
}
