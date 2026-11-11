#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long l=0,n=0,sum=0,j,sl=0;
    char a;
    string s;
    cin>>n;
    for (long long i=0;i<n;i++){
        cin>>sum>>a;
        for (j=l;j<l+sum;j++){
            s[j]=a;
        }
        l=j;
    }
    for (long long i=0;i<l/2;i++){
        if (s[i]!=s[l-i-1]){
            s[l-i]=s[i];
            sl++;
        }
    }
    cout<<sl<<endl;
    return 0;
}
