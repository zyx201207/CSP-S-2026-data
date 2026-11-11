#include <bits/stdc++.h>
using namespace std;
string a,b,a1;
int t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k;
    cin>>n>>m;
    cin>>a;
    for(int i=0;i<n;i++){
        a1=a.substr(i);
        for(int j=0;j<a1.size();j++){
            k=b.find(a1[j]);
            if(k!=-1){
                b.erase(k);
                b+=a1[j];
            }
            b+=a1[j];
        }
        for(int j=0;j<b.size();j++){
            t[b[j]]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<t[i];
    }
}
