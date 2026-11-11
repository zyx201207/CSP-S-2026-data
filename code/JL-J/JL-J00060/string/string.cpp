#include<bits/stdc++.h>
using namespace std;
int n,k,k2,ks,sum;
long long a[200001];
char b[200001];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1]){
            ks++;
        }
    }
    if(ks==n-1){
        cout<<0;
        return 0;
    }
    ks=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            ks++;
        }
    }
    if(ks==n-1){
        k2=n-1;
        for(int i=0;i<n/2;i++){
            if(b[i]!=b[k2]){
                sum+=a[i];
            }
            k2--;
        }
        cout<<sum;
        return 0;
    }
    //tepan
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s[k]=b[i];
            k++;
        }
    }
    k2=k;
    for(int i=0;i<k/2;i++){
        if(s[i]!=s[k2]){
            sum++;
        }
        k2--;
    }
    cout<<sum;
    return 0;
}

