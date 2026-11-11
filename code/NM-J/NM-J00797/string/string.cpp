#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long b[200005];
long long s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,p,q;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>b[i]>>a[i];
    }
    p=1;q=n;
    for(i=1;i<=n;i++){
        if(p>=q){
            break;
        }
        if(a[p]!=a[q]){
            if(b[p]>b[q]){
                s+=b[q];
                b[p]-=b[q];
                q--;
            }else if(b[p]==b[q]){
                s+=b[p];
                p++;q--;
            }else{
                s+=b[p];
                b[q]-=b[p];
                p++;
            }
        }else{
            if(b[p]>b[q]){
                b[p]-=b[q];
                q--;
            }else if(b[p]==b[q]){
                p++;q--;
            }else{
                b[q]-=b[p];
                p++;
            }
        }
    }
    cout<<s;
    return 0;
}
