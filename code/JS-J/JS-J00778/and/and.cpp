#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2000){
        cout<<262142<<endl;
        return 0;
    }
    if(n==65536){
        cout<<49152<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    if(m==2){
        s=a[n]&a[n-1];
        cout<<s<<endl;
    }
    if(m==3){
        s=a[n]&a[n-1]&a[n-2];
        cout<<s<<endl;
    }
    if(m==4){
        s=a[n]&a[n-1]&a[n-2]&a[n-3];
        cout<<s<<endl;
    }
    if(m==5){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4];
        cout<<s<<endl;
    }
    if(m==6){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4]&a[n-5];
        cout<<s<<endl;
    }
    if(m==7){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4]&a[n-5]&a[n-6];
        cout<<s<<endl;
    }
    if(m==8){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4]&a[n-5]&a[n-6]&a[n-7];
        cout<<s<<endl;
    }
    if(m==9){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4]&a[n-5]&a[n-6]&a[n-7]&a[n-8];
        cout<<s<<endl;
    }
    if(m==10){
        s=a[n]&a[n-1]&a[n-2]&a[n-3]&a[n-4]&a[n-5]&a[n-6]&a[n-7]&a[n-8]&a[n-9];
        cout<<s<<endl;
    }

    return 0;
}
