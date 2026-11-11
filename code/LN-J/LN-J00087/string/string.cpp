#include<bits/stdc++.h>
using namespace std;
const int N=200050;
struct node{
int a;
char b;
}g[N];
int n;
int ans=0;
long long num=0;
int main(){
     freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
            cin>>g[i].a;
            cin>>g[i].b;
        }


for(int i=1;i<=n;i++){
    num+=g[i].a;
}
long long i=1,j=num;
long long ii=1,jj=n;
long long iii=1,jjj=num;
while(i<j){
    if(i>g[ii].a){
        ii++;
        iii=i;
    }
    if(j<g[jj].a){
        jj--;
        jjj=j;
    }
    if(g[ii].b!=g[jj].b){
        ans+=1;
    }
 i++;j--;
}
cout<<ans;
}
