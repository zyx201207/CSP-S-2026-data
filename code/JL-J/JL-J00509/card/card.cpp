#include <bits/stdc++.h>
using namespace std;
long long a[50006],b[50006],c[50006],d[50006],i,n;
int yx(int u){
for(int q=u;q<=i;q++){
        b[q]=a[q];
    if(d[b[q]]){
        for(int w=d[b[q]];w<q;w++) {d[b[w]]=0; b[w]=0;}
    }
    d[b[q]]=q;
}
}
int cz(int u){
for(int q=u;q<=i;q++){
     c[b[q]]++;
}
for(int q=1;q<=i;q++){
    d[q]=0;
    b[q]=0;
}
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>i>>n;
for(int q=1;q<=i;q++){
    cin>>a[q];
}
for(int q=1;q<=i;q++){
    yx(q);
    cz(q);
}
for(int q=1;q<=n;q++){
    cout<<c[q]<<' ';
}
fclose(stdin);
fclose(stdout);
return 0;
}
