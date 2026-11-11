#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
char c[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    long long y=1e9;
    long long r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=0;j<a[i];j++){
            s=s+c[i];
        }
    }
    if(n==1){
        cout<<"0";
    }
    long long x=s.size();
    cout<<x/2;
    return 0;
}
