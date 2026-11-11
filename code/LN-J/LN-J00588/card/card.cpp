#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[200005],d[200005],org[200005];
void r(int times){
    if(times>a){
        for(int i=1;i<=a;i++){
            d[c[i]]++;
        }
        return;
    }
    for(int i=times;i<=a;i++){
        for(int j=times;j<=i;j++){
            if(i!=j && c[i]==c[j]){
                for(int k=times;k<j;k++){
                    c[k]=0;
                }
                d[c[i]]++;
                c[i]=0;
            }
        }
    }
    for(int i=1;i<=a;i++){
        c[i]=org[i];
    }
    r(times+1);

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
        org[i]=c[i];
    }
    r(1);
    for(int i=1;i<=b;i++){
        cout<<d[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
