#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,m=0,k=0;
    char c,s[1000001]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s[k+j]=c;
        }
        k+=a;
    }
    long long l=strlen(s);
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]){
            m++;
        }
    }
    cout<<m;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
