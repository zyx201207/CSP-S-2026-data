#include<bits/stdc++.h>
using namespace std;
struct Node{
    int l;
    int c;
    int b;
}a[200010];
string ttt(int n){
    string s;
    while(n!=0){
        if(n%2==1) s="1"+s;
        else{
            s="0"+s;
        }
        n/=2;
    }
    return s;
}
int c1(string s){
    long long cnt=0;
    int i=0;
    while(s[i]=='1'){
        cnt++;
        i++;
    }
    return cnt;
}
bool cmp(Node x,Node y){
    if(x.c!=y.c) return x.c>y.c;
    if(x.l!=y.l) return x.l>y.l;

    return x.b>y.b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       string s=ttt(x);
       a[i].l=s.size();
       a[i].c=c1(s);
       a[i].b=x;
    }
    sort(a+1,a+n+1,cmp);
 int sum=a[1].b;

    for(int i=2;i<=m;i++){
        int l=(a[i].b);
//cout<<l<<" ";
        sum=(sum&l);

    }
    cout<<sum;
    return 0;


}
