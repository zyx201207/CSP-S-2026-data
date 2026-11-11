#include<bits/stdc++.h>
using namespace std;
string s;
int j=1;
void solve(int a,char b){
    int x=j;
    for(int i=j;i<j+a;i++){
        s[i]=b;
        x++;
    }
    j=x;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a,cnt=0;
    char b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        solve(a,b);
    }
    for(int i=1;i<j;i++){
        if(s[i]!=s[j-1]){
            cnt++;
        }
        j--;
    }
    cout<<cnt;
    return 0;
}
