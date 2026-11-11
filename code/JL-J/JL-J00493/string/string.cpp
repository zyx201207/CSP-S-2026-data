#include<bits/stdc++.h>
using namespace std;
int n,z;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int s;
        char q;
        scanf("%d",&s);
        cin>>q;
        while(s){
            s--;
            a+=q;
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        b+=a[i];
    }
    for(int i=0;i<=(a.size()/2);i++){
        if(a[i]!=b[i]){
            z++;
        }
    }
    cout<<z;
    return 0;
}

