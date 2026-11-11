#include<bits/stdc++.h>
using namespace std;
char b[200001],t,z;
long long a[200001],s,l,r,m;
int n,i,j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    i=1;j=n-1;m=a[0];l=a[0];s=0;t=b[0];
    while(i<=j){
        if(l<=r){
            l+=a[i];
            if(b[i]!=z)
                s+=min(a[i],m);
            t=b[i];
            i++;
        }
        else{
            r+=a[j];
            if(b[j]!=t)
                s+=min(a[j],m);
            z=b[j];
            j--;
        }
        if(l<=r)m=r-l;
        if(l>r)m=l-r;
    }
    cout<<s;
    return 0;
}
