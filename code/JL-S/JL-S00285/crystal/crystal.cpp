#include<bits/stdc++.h>
using namespace std;
long a[10000],b,c,e[10000];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>b>>c;
    for(int i=0;i<b;i++){
        cin>>a[i];
        e[i]=a[i];
    }
    a[b]=a[b-1];
    e[b]=a[b];
    for(int i=0;i<b;i++){
        if(a[i]>a[i+1]){
            e[i+1]=a[i];
            e[i]=a[i+1];
            a[i]=e[i];
            a[i+1]=e[i+1];
        }
    }
    for(int i=0;i<c;i++){
        e[i]+=1;
        if(e[i]==e[i+1]){
            e[i]=e[i+1]*2;
        }
        if(e[i]>=e[b-1]){
            cout<<i;
            break;
        }
    }
    return 0;
}
