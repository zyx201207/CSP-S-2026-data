#include<bits/stdc++.h>
using namespace std;
string a,a1;
char d;
long long b,c,sum,k=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>c;
    for(int i = 1;i<=c;i++){
        cin>>b>>d;
        sum+=b;
        a+=d*b;
    }
    for(int i=a.size()-1;i>=0;i--){
        a1+=a[i];
        if(a1[i]!=a[a.size()-i-1]){
            k++;
        }
    }
    cout<<k/2;
    return 0;
}
