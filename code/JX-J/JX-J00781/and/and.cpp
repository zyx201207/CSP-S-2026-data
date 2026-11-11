#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,s,d,f,g,o;
    int w[200000];
    cin>>a>>s;
    d=0;
    for(int q=0;q<a;q++)
    {
        cin>>w[q];
    }
    for(int q=1;q<a;q++)
    {
        if(w[q]==w[q-1])
        {
            d++;
        }
    }
    if(d==a-1)
    {
        cout<<w[0];
    }
    return 0;
}

