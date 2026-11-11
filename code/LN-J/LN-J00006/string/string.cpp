#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
long long len,sum;
char c[200010];
string s;
string jianchuan(int l,char aim){
    string q="";
    while(l--) q+=aim;
    return q;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>c[i],len+=a[i],s+=jianchuan(a[i],c[i]);
    cout<<s<<'\n';
    int l=0,r=n-1;
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]) sum++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
