#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
struct HW{
    int a;
    char c;
}s[N];
int main(){
    frepoen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
        cin>>s[i].c;
    }
    if(n==1){
        cout<<"0";
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i].c==s[i+1].c){
            cnt++;
        }
    }
    if(cnt==n-1){
        cout<<"0";
    }
    return 0;
}
