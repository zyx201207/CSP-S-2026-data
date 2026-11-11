#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    //
    int n,a[1234567],q=0,y=0;
    string b[1234567],c[1234567];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++){
            c[q]=b[i];
            q++;
        }
    }
    for(int i=0;i<q/2;i++){
        if(c[i]!=c[q-i]){
            y++;
        }
    }
    cout<<y;
    return 0;
}
