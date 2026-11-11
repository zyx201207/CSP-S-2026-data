#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j = 1;j<=a[i];j++) s+=c[i];
    }
    int len = s.size();
    int mid = len/2;
    if(len%2 == 1){
        int ans = 0;
        for(int i = 0,j = len-1;i<mid&&j>mid;i++,j--){
            if(s[i]!=s[j]) ans++;
        }
        cout<<ans;
    }
    else{
        int ans = 0;
        if(s[mid]!=s[mid+1]) ans++;
        for(int i = 0,j = len-1;i<mid&&j>(mid+1);i++,j--){
            if(s[i]!=s[j]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
