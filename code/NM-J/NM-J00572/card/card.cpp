#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long n[a],m[b];
    for(long long i=0;i<a;i++){
        cin>>n[i];
        m[n[i]]=i;
    }
    for(long long i=0;i<b;i++){
        cout<<m[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
