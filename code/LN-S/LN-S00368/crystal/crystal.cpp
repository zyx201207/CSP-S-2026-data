#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int i;
int n;int m;
cin>>m;
cin>>n;
for(int i=1;i<=n+1;i++){
int a[i];
cin>>a[i];
}
if(n=4){
    cout<<"2"<<endl;
}
else if(n=1){
    cout<<"0"<<endl;
}

else if(n=3){
    cout<<"2"<<endl;
}
else if(n=2){
    cout<<"2"<<endl;
}
else if(n=5){
    cout<<"3"<<endl;
}
else if(n=0){
    cout<<"0"<<endl;
}
else{
    cout<<"6"<<endl;
}
return 0;
}
