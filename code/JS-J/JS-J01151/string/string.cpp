#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll l,r;
    char c;
};
int n;
vector<node> a;
char find(int pos){
    for(int i=0;i<a.size();i++){
        if(a[i].l<=pos&&a[i].r>=pos){
            return a[i].c;
        }
    }
}
/*char find1(ll pos){
    int le=1,ri=a.size(),mid,ans;
    while(le<ri){
        mid=(le+ri)>>1;
        if(a[mid].l<=pos){
            le=mid+1;
            ans=mid;
        }
        else{
            ri=mid-1;
        }
    }
    return a[ans].c;
}*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll pos=1,l=0,x;
    char ch;
    for(int i=0;i<n;i++){
        cin>>x>>ch;
        a.push_back({pos,pos+x-1,ch});
        l+=x;
        pos+=x;
    }
    ll cnt=0;
    for(int i=1;i<=ceil(l*1.0/2);i++){
        if(find(i)!=find(l-i+1)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
