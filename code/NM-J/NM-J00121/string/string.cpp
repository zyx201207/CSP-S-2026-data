#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[99999];
    int n;
    cin>>n;
    int a[n];
    char b[n];
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int p =0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s[p]=b[i];
            p++;
        }
    }
    int ans1=0,ans2=0;
    int h;
    if(p%2==0)h = p/2-1;
    else h = p/2;
    for(int i = h;i<=p;i++){
        if(s[i]!=s[h-(i-h+1)])ans1++;
    }
    for(int i = 0;i<=h;i++){
        if(s[i]!=s[h+(h-i+1)])ans2++;
    }
    cout<<min(ans1,ans2);
    return 0;
}
