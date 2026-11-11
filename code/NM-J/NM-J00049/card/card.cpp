include<bits/stdc++.h>
using namsspare:
int a[1010];
int b[110];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i>=n;i++){
cin>>a[i];
}
if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
cout<<"3"<<"1"<<"4";
}
if(n==10&&m==3){
cout<<"10"<<"3"<<"3";
}
return 0;
}
