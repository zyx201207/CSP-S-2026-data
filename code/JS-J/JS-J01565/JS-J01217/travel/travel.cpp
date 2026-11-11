#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
string a,a1,b,b1;//a,b chexiang,a1,b1,shizuowei
cin>>a>>a1>>b>>b1;
int che=0;
  if(a==b){
        cout<<1;
        che=1;
  }else{
  cout<<0;
  }
  int k=0;//tongyilie
//==tongchexiang
   if(a1[0]==b1[0]&&a1[1]==b1[1]&&che){
    cout<<1;
    k=1;
   }else{
   cout<<0;
   }
//tong lie

    num[a1[2]-'A'+1]+=1;
   num[b1[2]-'A'+1]+=1;
   int sum1=0,sum2=0;
   for(int i=1;i<=3;i++){
    sum1+=num[i];
   }
   for(int i=4;i<=5;i++){
    sum2+=num[i];
   }
   int lie=0;
   if(k=1&&(sum1==2||sum2==2)&&che){
    cout<<1;
    lie=1;
   }else{
   cout<<0;
   }
//  tong bian
   if(sum2==2&&k==1&&lie==1&&che){
    cout<<1;
   }else if(lie==1&&k==1&&num[2]==1&&che){
   cout<<1;
   }else{
   cout<<0;
   }
  // cout<<num[1]<<" "<<num[2]<<" "<<num[3]<<" "<<num[4]<<" "<<num[5]<<endl;
   //cout<<a1[2]-'A'+1<<" "<<b1[2]-'A'+1;

   return 0;
}
