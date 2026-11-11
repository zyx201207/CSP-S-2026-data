#include<bits/stdc++.h>
using namespace std;
string s1;
char m;
long long sum=0;
long long ans=0;
long long n=0,n1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        cin>>m;
        for(int j=sum;j<sum+n1;j++){
            s1[j]=m;
        }
        sum+=n1;
    }
    for(int i=0;i<sum;i++){
        if (s1[i]!=s1[sum-1-i]){
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}

