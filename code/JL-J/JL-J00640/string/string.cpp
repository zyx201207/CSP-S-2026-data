#include<bits/stdc++.h>
using namespace std;
long long k[200020];
char a[200020];
long long cn,n,v,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>cn;
    for(int i=1;i<=cn;i++){
        cin>>k[i];
        cin>>a[i];
        n+=k[i];
    }
    v=n/2;
    int b=1,c=cn;
    for(int i=1,j=n;i<=v&&j>=v;i++,j--){
            if(i>k[b])b++;
            if(j<k[c])c--;
            if(a[b]!=a[c]){
                cnt++;
            }
    }
    cout<<cnt;
    return 0;
}
