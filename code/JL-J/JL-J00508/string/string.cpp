#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],h,x;
char c[200010];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=10){
        for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
            h+=a[i];
            for(int j=1;j<=a[i];j++)
                s+=c[i];
        }
        int t=(h+1)/2;
        int l=1,r=h;
        for(;l<=t;l++){
            if(s[l]!=s[r])
                x++;
            r--;
        }
        cout<<x;
        return 0;
    }
    if(n<=2000){
        for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
            h+=a[i];
            if(a[i]>1000)return 0;
            for(int j=1;j<=a[i];j++)
                s+=c[i];
        }
        int t=(h+1)/2;
        int l=1,r=h;
        for(;l<=t;l++){
            r--;
            if(s[l]!=s[r])
                x++;
        }
        cout<<x;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
            h+=a[i];
            if(a[i]>1000)return 0;
            for(int j=1;j<=a[i];j++)
                s+=c[i];
        }
        int t=(h+1)/2;
        int l=1,r=h;
        for(;l<=t;l++){
            r--;
            if(s[l]!=s[r])
                x++;
        }
        cout<<x;
    }
    return 0;
}
