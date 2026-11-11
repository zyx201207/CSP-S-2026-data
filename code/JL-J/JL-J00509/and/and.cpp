#include <bits/stdc++.h>
using namespace std;
long long a,b,i[20005],n[20005],max0=0,e=0,v,x;
int cz(int u){
    e=0;
for(int q=1;q<=a;q++){
     v=i[q]&u;
    if(n[q]==1&&v>e) {
            e=v;
            x=q;
    }
   }
n[x]=0;
b--;
if(b>0) return cz(e);
else return e;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>a>>b;
for(int q=1;q<=a;q++){
    cin>>i[q];
    n[q]=1;
    if(i[q]>max0) max0=i[q];
}
for(int q=1;q<=a;q++){
    if(i[q]==max0) {n[q]==0;break;}
}
cout<<cz(max0);
return 0;
}
