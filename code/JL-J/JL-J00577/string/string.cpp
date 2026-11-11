#include<bits/stdc++.h>
using namespace std;
long long n,b,f,c,a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s;
    char r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>r;
        s[i]=r;
        if(s[i]==s[i-1]){
            a[i]+=a[i-1];
            a[i-1]=0;
        }
    }
    for(int i=1;i<=n/2;i++){
        if(s[i]==s[n-i+1]&&a[i]==a[n-i+1]){
            c++;
        }
    }
    if(c==n){
        b=0;
    }else if(n%2==1&&n>=3){
        for(int i=1;i<=n;i++){
            if(a[i]>b){
                b=a[i];
            }
        }
    }else if(n<3){
        b=a[1];
        for(int i=1;i<=n;i++){
            if(a[i]<b){
                b=a[i];
            }
        }
    }else if(n%2==0&n>=3){
        b=a[1];
        for(int i=1;i<=n;i++){
            if(a[i]!=b){
                f=1;
            }
        }
        if(f==1){
            for(int i=1;i<=n;i++){
                if(a[i]>b){
                    b=a[i];
                }
            }
        }else if(f==0){
            b=a[1];
        }
    }
    cout<<b;
}
