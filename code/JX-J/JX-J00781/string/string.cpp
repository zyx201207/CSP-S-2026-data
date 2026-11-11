#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,s,d,f,g,o,h;
    o=0;
    d=0;
    int q;
    char cs;
    char w[200000];
    cin>>a;
    for(int p=0;p<a;p++)
    {
        cin>>q>>cs;
        for(int oi=0;o<q;o++)
        {
            w[o]=cs;
        }
    }
    g=sizeof(w);
    h=sizeof(w);
    for(int p=0;p<h/2;p++)
    {
        if(w[p]!=w[g])
        {
            d++;
            g--;
        }

    }


    cout<<d;
    return 0;
}










