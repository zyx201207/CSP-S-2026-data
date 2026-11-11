#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
string c[N];
bool is_rev(string a)
{
    int len=a.size();
    for(int i=0;i<len;i++){
        int r=1;
        if(a[i]==a[len-r]) continue;
        else return 0;
        r++;
    }
    return 1;
}
int to_be(string s){
    if(is_rev(s)) return 0;
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len;i++){
        int r=1;
        if(s[i]!=s[len-r]){
            s[len-r]=s[i];
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int i=0;
    while(a[i]){
        s+=c[i];
        --a[i];
        if(!(a[i])) i++;
    }
    cout<<to_be(s);
    return 0;
}
