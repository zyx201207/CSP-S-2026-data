#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000000],s=1,s1=0;
    char b[1000000],c[1000000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        for(int j=1;j<=a[i];j++)
        {
            c[s]=b[i];
            s++;
        }
    }
    s=s-1;
    for(int i=1;i<=s/2;i++)
    {
        if(c[i]!=c[s-i+1])
        {
            s1++;
        }
    }
    cout<<s1;
	return 0;
}

