#include<bits/stdc++.h>
using namespace std;
int n;
long long t[200010],cnt,a[200010];
char s[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>s[i];
        a[i]=a[i-1]+t[i];
    }
    for(long long i=1;i<=a[n]/2;i++){
        long long x=i;
        long long y=a[n]+1-x;
        char str1,str2;
        for(int i=0;i<n;i++){
            if(x>a[i]&&x<=a[i+1]){
                str1=s[i+1];
            }
            if(y>a[i]&&y<=a[i+1]){
                str2=s[i+1];
            }
        }
        if(str1!=str2) cnt++;
    }
    cout<<cnt;
    return 0;
}
