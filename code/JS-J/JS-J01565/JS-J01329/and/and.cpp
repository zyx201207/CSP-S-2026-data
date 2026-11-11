#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
struct And{
    int num,t[35]={0},w=0;
}a[N];
void ttt(int j){
    int z=a[j].num;
    while(z>0){
        a[j].t[a[j].w]=z%2;
        z/=2;
        a[j].w++;
    }
    return ;
}
bool cmp(And o,And p){
    return o.num<=p.num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].num;
        ttt(i);
    }
    sort(a,a+n,cmp);
    for(int i=n-1;i>=0;i--){
        if(a[i].num==a[i-1].num){
            cout<<a[i].num;
            return 0;
        }
    }
    return 0;
}
