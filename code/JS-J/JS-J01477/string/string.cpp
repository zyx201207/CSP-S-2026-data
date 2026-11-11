#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s,c=0;
    string b;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s>>a;
        for(int j=1;j<=s;j++){
            b+=a;
        }
    }
    long long l=b.size(),mid=l/2;
    if(l%2==1){
        for(int i=0;i<=mid;i++){
            if(b[mid+i]!=b[mid-i]){
                c++;
            }else{
                continue;
            }
        }
    }else{
        mid--;
        if(b[mid]!=b[mid+1]){
            c++;
        }
        for(int i=1;i<=mid;i++){
            if(b[mid+i+1]!=b[mid-i]){
                c++;
            }else{
                continue;
            }
        }
    }
    cout<<c;
    return 0;
}
