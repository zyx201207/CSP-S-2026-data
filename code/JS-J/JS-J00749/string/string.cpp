#include<bits/stdc++.h>
using namespace std;
long long n,x,j=0;
char c,cc;
string s;
bool f=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        if(i==1) cc=c;
        if(cc!=c) f=0;
        j+=x;
        while(x--) s+=c;
    }
    long long jj=j;
    j-=1;
    if(f){
        cout<<"0";
        return 0;
    }
    long long i=0,k=0;
    if(jj%2!=0){
         while(i!=j){
            if(s[i]!=s[j]) k++;
            i++,j--;
        }
    }
   else{
    while(i!=(jj/2)){
        if(s[i]!=s[j]) k++;
        i++,j--;
   }
   }
    cout<<k;
    return 0;
}



