#include<bits/stdc++.h>
using namespace std;
long long m,num;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
    struct N{
    long long n;
    char x;
    }a[m];
    long long l=0,r=m-1;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].n>>a[i].x;
    }
    while(l<r)
    {
        int e=a[l].x-'a';
        int f=a[r].x-'a';
        if(a[l].n>a[r].n)
        {
            if(e!=f)num+=a[r].n;
            a[l].n-=a[r].n;
            r--;
        }
        else if(a[l].n<a[r].n){
            if(e!=f)num+=a[l].n;
            a[r].n-=a[l].n;
            l++;
        }
        else{
            if(e!=f)num+=a[r].n;
            l++;
            r--;
        }
    }
    cout<<num;
    return 0;
}
