#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n;
   cin>>n;
   string x;
   int a[n+5];
   int c;
   int sum=0,num=0;
   int y;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    cin>>c;
    x+=a[n+5]*c;
   }
   y=x.length();
   for(int p=1;p<=n;p++){
        if(x[p]!=x[y-p]){
            x[y-p]=x[p];
            sum++;
        }
   }
   for(int q=1;q<=n;q++){
        if(x[q]!=x[y-q]){
            x[q]=x[y-q];
            num++;
        }
   }
   if(sum>num){
        cout<<num;
   }
   else{
    cout<<sum;
   }
}
