#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    string b;
    cin>>a;
    for(int i=1;i<a;i++){
        int h;
        char d;
        cin>>h>>d;
        for(int j=0;j<h;j++){
            b[j]=d;
        }
    }
    int k=0;
    for(int i=0;i<b.size();i++){
        if(b[i]!=b[b.size()-i]){
            k=k+1;
        }
    }
    cout<<k;
    return 0;
}
