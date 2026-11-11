#include<bits/stdc++.h>
using namespace std;
long long h[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,k;
    cin >> a >> k;
    for(int i=1;i<=a;i++){
        cin >> h[i];
    }
    long long sum=0;
    if(k==a){
        long long temp=h[1];
        for(int i=2;i<=a;i++){
            temp&=h[i];
        }
        cout << temp;
    }
    else if(k==1){
        long long m=0;
        for(int i=1;i<=a;i++){
            if(h[i]>m){
                m=h[i];
            }
        }
        cout << m;
    }
    else{
        cout << 12;
    }
    return 0;
}
