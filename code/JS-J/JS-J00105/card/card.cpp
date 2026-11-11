#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[300009];
string s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long  j=1;j<=n;j++){
        for(long long  i=j;i<=n;i++){
        char c=a[i]+'0';
        if(s.find(c)==-1){
            s=s+c;
        }
        else{
            long long xb=s.find(c);
            s.erase(s.begin()+xb,s.end());
            s=s+c;
        }
    }
    for(long long i=0;i<=s.size()-1;i++){
        long long xb=s[i]-'0';
        b[xb]++;
    }
    s="";
    }
    for(long long i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
