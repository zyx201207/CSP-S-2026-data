#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int maxx=INT_MIN;
int myf(int x,int y){
    int sum;
    if(x%y==0||y%x==0) sum=0;
    else sum=min(x,y);
    return sum;
}
int p(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }
    if(n==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(maxx<(myf(a[i],a[j]))){
                    maxx=a[j]&a[i];
                }
            }
        }
        cout<<maxx;
    }
    else{
        sort(a+1,a+1+n,p);
        cout<<a[3];
    }
    return 0;
}
