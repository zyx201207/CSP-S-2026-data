#include<bits/stdc++.h>
using namespace std;
long long n=0,ans=0,k[100000005],c=0,w=1,p=0;
char a[100000005];
char s[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>k[i]>>s[i];
        if(k[i]!=k[i-1]){
            w=0;
        }
    }
    if(w==0){
      for(long long i=0;i<n;i++){
        for(long long j=0;j<k[i];j++){
            a[c]=s[i];
            c++;
        }
      }
    }else{
        p=k[0];
        for(long long i=0;i<n;i++){
            k[i]=1;
        }
    }


    for(long long i=0;i<(c/2);i++){
        if(a[i]!=a[c-i-1]){
            ans++;
        }
    }
    if(p!=0){
        cout<<ans*p;
    }else{
        cout<<ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
