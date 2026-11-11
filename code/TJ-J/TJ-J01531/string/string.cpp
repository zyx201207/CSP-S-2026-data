#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string d="";
    int a,b,sum=0;
    cin>>a;
    char c;
    for (int i=1;i<=a;i++){
        cin>>b>>c;
        for (int i=1;i<=b;i++){
            d+=c;
        }
    }
    int l=0,r=d.size()-1;
    while (1){
        if (l==r){
            break;
        }
        else{
            if (d[l]!=d[r]){
                sum++;
            }
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}
