#include<bits/stdc++.h>
using namespace std;
long long n,l,x,cnt;
char s[200005];
long long al[200005],ar[200005],k1,k2,i,j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>ar[i]>>s[i];
        l+=ar[i];
        ar[i]+=x;
        al[i]=x+1;
        x=ar[i];
    }
    k1=1;k2=l;i=1;j=n;
        while(k1<k2){
            if(ar[i]-k1<k2-al[j]){
                if(s[i]!=s[j]){
                    cnt+=al[i+1]-k1;
                }
                k2-=(al[i+1]-k1);
                k1=al[i+1];i++;
            }else if(ar[i]-k1>k2-al[j]){
                if(s[i]!=s[j]){
                    cnt+=k2-ar[j-1];
                }
                k1+=k2-ar[j-1];
                k2=ar[j-1];j--;
            }else{
                if(s[i]!=s[j]){
                    cnt+=k2-ar[j-1];
                }
                k2=ar[j-1];j--;
                k1=al[i+1];i++;
            }
        }cout<<cnt;

    return 0;
}
