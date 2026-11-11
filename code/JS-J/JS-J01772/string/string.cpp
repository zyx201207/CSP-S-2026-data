#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n;
struct node{
    long long num;
    char ch;
}a[N]; 
node lst;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].num>>a[i].ch;
    }
    int l = 1,r = n;
    bool  lstn = 0;
    long long ret = 0;
    while(l<=r){
       if(a[l].ch!=a[r].ch){
           ret += min(a[l].num,a[r].num);
           //cout<<l<<" "<<r<<endl;
           if(a[r].num>a[l].num){
              
               a[r].num-=a[l].num; 
               l++;
           }
           else if(a[l].num>a[r].num){
               a[l].num-=a[r].num;
               r--;
           }
           else {
               l++;
               r--;
           }
       }
       else{
           if(a[r].num>a[l].num){
              
               a[r].num-=a[l].num; 
               l++;
           }
           else if(a[l].num>a[r].num){
               a[l].num-=a[r].num;
               r--;
           }
           else {
               l++;
               r--;
           }
       }
    }
    cout<<ret<<endl;
    return 0;
}