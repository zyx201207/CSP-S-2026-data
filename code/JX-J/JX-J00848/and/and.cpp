#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct l{
    int a,b[20005];
}s[20005];
/*bool cmp(num x,num y){
    return x.a>y.a;
}
int g(int chance){
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
    }
    sort(s+1,s+1+n,cmp);
}
    cout<<g(m,0);
    return 0;
}*/
void f(int x){
    int i=1,n=s[x].a;
    while(n!=0){
        s[i].b[i]=n%2;
        n/=2;
        i++;
    }
}
void g(){
    for(int i=1;i<=sizeof(s[n].b);i++){

    }
}
int work1(){
    for(int i=1;i<=n;i++)f(s[i].a);
    g();
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
    }
    sort(s+1,s+1+n);
    if(s[n].a<1073741824&&n<=20005)cout<<work1();
    return 0;
}
