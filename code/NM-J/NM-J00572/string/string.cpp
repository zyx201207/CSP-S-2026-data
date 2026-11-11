#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    cin>>a;
    string s="0";
    while (a--){
        long long b;
        char c;
        cin>>b>>c;
        while(b--){
            s+=c;
        }
    }
    a=s.size()-1;
    long long x=(a+1)/2,y=x;
    for(long long i=1,j=a+1;i<=x;i++,j--){
        if(s[i]==s[j]){
            y--;
        }
    }
    cout<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
