#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n,d,f=0;
bool lu(int x,int y){
    if(a[y]-a[x]<=d){
        return 1;
    }
    else if(a[y-1]-a[x]<=d){
        return lu(x,y-1)+1;
    }
    else{
        return 0;
    }
}
bool fei(int x,int y){
    if(a[y]-a[x]<=d){
        return 1;
    }
    else if(a[y]-a[x+1]<=d){

        return lu(x+1,y)+1;
    }
    else{
        return 0;
    }
}
void qian(int n,int d){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
        if(lu(i,j)==fei(i,j) and a[j]-a[i]%d!=0){
            f++;
        }
        }
    }
}
int main(){
    int c,t;

    cin>>c>>t;
    for(int i=1;i<=t;i++){
            cin>>n>>d;
        qian(n,d);
        cout<<f;
        f=0;
    }
    return 0;
}
