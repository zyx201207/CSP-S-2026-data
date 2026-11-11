#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    long long s=0,n,n1;
    char n2;
    string a="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>n1>>n2;
        for(int j=1;j<=n1;j++){
            a+=n2;
        }
    }
   // cout<<a<<endl;
    long long q=1,l=0,r=a.size()-1;
    for(int i=0;i<=a.size();i++){
        if(a[l]==a[r]){
            q=1;
        }
        else {
            s++;
            a[r]=a[l];
            //cout<<1<<':';
        }
        //cout<<l<<':'<<a[l]<<' '<<r<<':'<<a[r]<<endl;
        if(l==r)break;
        l++;
        r--;

    }
    cout<<s;
    return 0;
}
