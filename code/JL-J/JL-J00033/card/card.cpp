#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,c[10005],d;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>c[i];
    }
    while(c[1]!=0){
        for(int j=0;j<a;j++)
        {
            c[j]=c[j+1];
            d+=1;
        }
        for(int k=1;k<=d;k++)
        {
            for(int l=0;l<=b;l++){
                if(c[l]==k){
                    cout<<k<<" ";
                }
            }
        }
    }
    return 0;
}

