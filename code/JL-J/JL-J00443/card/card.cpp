#include<bits/stdc++.h>
using namespace std;
int m[100000].p[100000]
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int a,b,l=0;
    cin>>a>>b;
    int n[a];
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    for(int i=0;i<a;i++){
        l=0;
        for(int j=i-1;j<a;j++){
            m[l]=n[a];
            for(int h=0;h<l-1;h++){
                if(m[h]==m[l]){
                    for(int k=h;k<=l;k++){
                        m[k]=0;
                    }
                    l=h;
                    break;
                }
            }
        }
        for(int i=0;i<l;i++){
            p[m[i]]+=1;
        }
    }
    for(int i=0;i<100000;i++){
        if(p[i]!=0){
            cout<<i<<" ";
        }
    }
}
