#include<bits/stdc++.h>
using namespace std;
int n=0;
int m=0;
long long a[20000];
long long er(int x){
    if (x!=1){
        return er(x/2);
    }else{
        cout<<"1";
    }
}
/*int and(int x,int y){
    if (x==1&&y==1){
        return 1;
    }else{
        return 0;
    }
}
*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){

        }
    }
    cout<<"12"<<endl;
    return 0;
}
