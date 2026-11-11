#include<bits/stdc++.h>
using namespace std;
long long a[100];
char b[100];
long long c[100];
char d[100];
long long cnt1=0,cnt2=0;
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int x=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[x]=a[i];
        d[x]=b[i];
        x--;
    }
    int j=n;
    int i=1;
    while(j>i){
        if(b[i]!=b[j]){
            if(a[i]>=a[j])
                cnt1+=a[j];
            else
                cnt1+=a[i];
        }
        i++;
        j--;
    }
    j=n;
    i=1;
    while(j>i){
        if(d[i]!=d[j]){
            if(c[i]>=c[j])
                cnt2+=c[j];
            else
                cnt2+=c[i];
        }
        i++;
        j--;
    }
    cout<<min(cnt1,cnt2);
    return 0;
}
