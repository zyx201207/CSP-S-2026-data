#include<bits/stdc++.h>
using namespace std;
int q,a,z,w,e[9];
char n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>q>>a>>n>>z>>w>>m;
    if(q==z){
        e[1]=1;
        if(a==w){
            e[2]=1;
            if((n<='C'&&m<='C')||(n>='D'&&m>='D')){
                e[3]=1;
                if(abs(n-m)==1||(abs(n-m)==2 && (m=='F'||n=='F'))) e[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) cout<<e[i];
    fclose(stdin);
    fclose(stdout);
}
