#include<bits/stdc++.h>
using namespace std;
long long a,b,flag,c[1000000],d[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            flag=0;
            for(int z=j+1;z<a;z++){
                if(c[j]==c[z]){
                    j=z-1;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                d[c[j]-1]=d[c[j]-1]+1;
            }
        }
    }
    for(int i=0;i<b;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
