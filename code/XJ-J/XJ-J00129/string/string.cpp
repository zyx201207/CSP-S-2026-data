#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    string b,z;
    cnt=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        while(a--) z+=b;
    }
    int j=z.length()-1;
    for(int i=0;i<=z.length()/2;i++){
        if(!(z[i]==z[j])) cnt++;
        j--;
    }
    cout<<cnt;
    return 0;
}
