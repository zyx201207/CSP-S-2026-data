#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a,l,k,p,h;
string s,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>s;
        for(j=0;j<a;j++){
            t=t+s;
        }
    }
    if(int(t.size())%2==1){
        l=(t.size()-1)/2;
        for(i=1;i<=l;i++){
            if(t[l-i]!=t[l+i]){
                k++;
            }
        }
        cout<<k;
    }
    else{
        p=t.size()/2;
        for(j=0;j<p;j++){
            if(t[p-j-1]!=t[p+j]){
                h++;
            }
        }
        cout<<h;
    }
    return 0;
}
