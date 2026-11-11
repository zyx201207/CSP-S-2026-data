#include<bits/stdc++.h>
using namespace std;
struct abc{
    int a;
    char c;
}a[200005];
long long n,len,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s+='0';
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i].a,&a[i].c);
        len+=a[i].a;
        for(int j=1;j<=a[i].a;j++){
            s=s+a[i].c;
        }
    }
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[len-i+1]){
            ans++;
        }
    }
    cout<<s<<" "<<len<<" "<<ans;
    return 0;
}
