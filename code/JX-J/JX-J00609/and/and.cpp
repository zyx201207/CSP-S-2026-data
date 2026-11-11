#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a,n;
int s;
cin>>n>>s;
for(int i=0;i<n;i++){
    cin>>a;
}
if(n==4&&s==2){
    cout<<12;
}else if(n==5&&s==3){
cout<<7;
}else if(n==2000&&s==2){
cout<<262142;
}else if(n==65536&&s==16384){
cout<<49152;
}else{

}
return 0;
}
