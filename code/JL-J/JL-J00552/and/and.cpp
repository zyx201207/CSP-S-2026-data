#include<bits/stdc++.h>
using namespace std;
string t(int x){
    string s;
    while(x){
        s+=x%2+'0';
        x/=2;
    }
    int l=s.size()-1;
    for(int i=0;i<=l/2;i++){
        swap(s[i],s[l-i+1]);
    }
    return s;
}
struct node{
    int num;
    string tw;
}a[200005];
bool cmp(node x,node y){
    return x.tw>y.tw;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].tw=t(a[i].num);
    }
    sort(a+1,a+n+1,cmp);
    int cnt=a[1].num;
    for(int i=2;i<=m;i++){
        cnt&=a[i].num;
    }
    cout<<cnt;
    return 0;
}
