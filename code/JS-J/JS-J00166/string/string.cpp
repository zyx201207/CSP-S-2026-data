#include<bits/stdc++.h>
using namespace std;
string str="";
int n,a;
char c;
long long l,r,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--){
            str+=c;
        }
    }
    l=0;
    r=str.size()-1;
    while(l<=r){
        if(str[l]!=str[r])
            ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
