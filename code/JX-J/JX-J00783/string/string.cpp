#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,w;
char c;
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int i=0;i<a;i++) b+=c;
        w+=a;
    }
    for(int i=0;i<b.size()/2+1;i++){
        if(b[i]!=b[w-1]){
            b[w-1]=b[i];
            cnt++;
        }
        w--;
    }
    cout<<cnt;
    return 0;
}
