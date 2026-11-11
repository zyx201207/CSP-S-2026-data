#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int  a;cin>>a;
    string o="";
    for (int i=1;i<=a;i++){
        long long z;
        char x;
        cin>>z>>x;
        for (int j=1;j<=z;j++){
            o+=x;
        }
    }long long sum=0;
    if (o.size()%2==0){
        for (int i=0;i<=o.size()/2-1;i++){
            if (o[i]!=o[o.size()-i-1]){
                sum++;
            }
        }
    }
    else {
        for (int i=0;i<=o.size()/2;i++){
            if (o[i]!=o[o.size()-i-1]){
                sum++;

            }
        }
    }cout<<sum;



    return 0;
}
