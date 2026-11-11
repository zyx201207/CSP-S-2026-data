#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n, cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int tmp;char c;cin>>tmp>>c;
        for(int j=1;j<=tmp;j++){
            s+=c;
        }
    }
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}
