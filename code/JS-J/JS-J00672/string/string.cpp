#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long L;
    cin>>L;
    string s;
    string q;
    long long l=0;
    long long a[10086];
    char b[10086];
    for(long long i=0;i<L;i++){
        cin>>a[i]>>b[i];
        for(long long j=0;j<a[i];j++){
            s+=b[i];
            l++;
        }
    }
    bool f1=1;
    for(int i=1;i<l;i++){
        if(b[i]!=b[i-1]){
            f1=0;
            break;
        }
    }
    if(f1){
        cout<<0;
        return 0;
    }
    bool f=1;
    for(int i=0;i<l/2;i++){
        if(a[i]!=a[l-i-1]||b[i]!=b[l-i-1]){
            f=0;
            break;
        }
    }
    if(f){
        cout<<0;
        return 0;
    }
    for(long long i=l-1;i>=0;i--){
        q+=s[i];
    }
    long long sum=0;
    for(long long i=0;i<l-1;i++){
        if(q[i]!=s[i]){
            q[i]=s[i];
            s[l-1-i]=q[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
