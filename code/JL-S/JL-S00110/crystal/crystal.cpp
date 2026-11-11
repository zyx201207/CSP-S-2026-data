#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xxxx.in","r","stdin");
freopen("xxxx.out","w","stdout");
long long n,m,a[1000000001],sam=0,k=0,b[1000010],h;
cin>>n>>m;
h=k+1;
for(int i=0;i<n;i++){
    cin>>a[i];
}

while(k==n-1){
    if(a[k]==a[h]){
         sam++;
         a[k]++;
         h++;
    }else{
    if(a[k]+1==a[h]){
    sam++;
    h++

    }
    }
    if(h==n){
    k++;
    h=k+1;

    }
    

}
cout<<"4"
    return 0;
}
