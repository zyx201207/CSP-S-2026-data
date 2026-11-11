#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string a="";
    int b;
    char c;
    for(int i=0;i<n;i++){
        cin >>b>>c;
        for(int j=0;j<b;j++){a+=c;}
    }
    long long q=0;
    long long w=a.size();
    for(int i=0;2*i<w;i++){
        if(a[i]!=a[w-1-i]){q++;}
    }
    cout <<q;
    return 0;
}


