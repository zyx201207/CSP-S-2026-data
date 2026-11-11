#include <bits/stdc++.h>
using namespace std;
struct node{
    int x;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0;
    cin>>n;
    node a[200005];
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].c;
    }
    int mi=INT_MAX;
    for(int i=0;i<n;i++){
        mi=min(a[i].x,mi);
    }
    int l=1;
    for(int i=2;i<=mi;i++){
        bool t=1;
        for(int j=0;j<n;j++){
            if(a[i].x%i!=0){
                t=0;
            }
        }
        if(t==1){
            for(int j=0;j<n;j++){
                a[i].x/=i;
            }
            l*=i;
        }
    }
    vector <char> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].x;j++){
            v.push_back(a[i].c);
        }
    }
    int le,ri;
    if(v.size()%2==0){
        ri=v.size()/2;
        le=ri-1;
    }else{
        le=v.size()/2-1;
        ri=le+2;
    }
    while(le>=0){
        if(v[le]!=v[ri]){
            s++;
        }
        le--;
        ri++;
    }
    s*=l;
    cout<<s;
    return 0;
}
