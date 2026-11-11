#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    long long a=0;
    vector<char> b;
    int c[n];
    for(int i=0;i<n;i++){
        cin >> c[i];
        char d;
        cin >>d;
        for(int j=0;j<c[i];j++) b.push_back(d);
        a+=c[i];
    }
    int num=0;
    int e=a/2-1;
    int f;
    if(a%2==0){
        f=a/2;
    }else{
        f=a/2+1;
    }
    for(int i=0;i<a/2;i++){
            if(b[e]!=b[f]){
                num++;
            }
            e--;
            f++;

    }
    cout << num;
    return 0;
}
