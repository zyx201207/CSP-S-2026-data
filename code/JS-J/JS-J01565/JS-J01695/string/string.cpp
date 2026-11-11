#include<bits/stdc++.h>;
using namespace std;
string s;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n;
   cin>>n;
   long long js=0;
   for(int i=0;i<n;i++){
    long long ans;
    cin>>ans;
     char zm;
    cin>>zm;
    for(int j=0;j<ans;j++){
        s+=zm;
        js++;
    }
   }
    long long box=0;
   if(js%2==0){
    for(int i=0;i<js/2;i++){
        if(s[i]!=s[js-1-i]){
            box++;
        }
    }
   }
   else {
    for(int i=0;i<(js-1)/2;i++){
        if(s[i]!=s[js-1-i]){
            box++;
        }
    }
   }
   cout<<box;
return 0;
}
