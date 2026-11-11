#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],c[200010];
char ch;
long long s[200010],C;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch;
        c[i]=ch;
        s[i]=s[i-1]+a[i];
    }
    long long S=s[n];
    for(int i=1,j=n;i<j;){
        if(s[i]+s[j-1]<S){
            if(c[i]!=c[j])C+=a[j]-a[i];
            j--;
        }
        else if(s[i]+s[j-1]==S){
            if(c[i]!=c[j])C+=min(a[i],a[j]);
            i++;
            j--;
        }
        else if(s[i]+s[j-1]>S){
            if(c[i]!=c[j])C+=a[i]-a[j];
            i++;
        }
    }
    cout<<C;
    return 0;
}
