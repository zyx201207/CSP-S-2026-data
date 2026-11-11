#include<iostream>
using namespace std;
int jg[10086];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
            cin>>a[i];
    }
    for(int k=0;k<n;k++){
        int b[n];
        int num=0,f=m;
        for(int bp=0;bp<n;k++){
            b[bp]=a[bp];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(f==0){
                    break;
                }
                else{
                    if(b[i]<b[j]){
                        if(b[j]-b[i]==1){
                            b[i]+=1;
                            f-=1;
                        } 
                    }
                }

            }
        }    
    }
    return 0;
}
