#include<bits/stdc++.h>
using namespace std;
char c[200005],ch;
long long n,a,temp=1,len,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>ch;
        len+=a;
        for(;temp<=len;temp++)c[temp]=ch;
    }
    for(int i=1;i<=len/2;i++)if(!(c[i]==c[len-i+1]))ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
