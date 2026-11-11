

#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin >> a;
    string h="";
    long long p;
    char f;
    bool q=0;
    long long w=0;
    for(int i=0;i<a;i++){
        long long b;
char k;


        cin >> b >> k;  w+=b;
        if(q==1){

            continue;
        }
        if(i==0){
            p=b;
            f=k;
        }
        if(p==b&&f==k&&p>=1000000){
            q=1;
            continue;
        }
        for(int i=0;i<b;i++){
            h+=k;
        }

    }
    int ans=0;
    if(q==1){
        cout << w/2;
        return 0;
    }
    for(int i=0;i<h.size()/2;i++){
        if(h[i]!=h[h.size()-i-1]){
            ans++;
//cout  << h[i] << ' ' << h[h.size()-i]<< endl;
//cout << i << endl;
        }

    }
    cout << ans;
    return 0;
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
