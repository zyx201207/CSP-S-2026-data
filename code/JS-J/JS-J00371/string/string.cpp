#include <bits/stdc++.h>
using namespace std;
struct cunchu{
long long left=0;
long long right=0;
char zimu;}
zifuchuan[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long  sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        zifuchuan[i].left=sum+1;
        cin>>zifuchuan[i].zimu;
        zifuchuan[i].right=sum+x;
        sum+=x;
    }
    long long  erfen=(sum+1)/2;
    long long ans =0;
    int bencii=0,bencij=0;
    for(int i=1,j=n;i<=n&& j>=1;){
        bool xiangtong=0;
    if(zifuchuan[i].zimu==zifuchuan[j].zimu)xiangtong=1;


        bencii=zifuchuan[i].right-zifuchuan[i].left+1;
        bencij=zifuchuan[j].right-zifuchuan[j].left+1;
        if(bencij>=bencii){
                if(xiangtong==0)ans+=zifuchuan[i].right-zifuchuan[i].left+1;
                    zifuchuan[j].right-=bencii;
                i++;
                if(zifuchuan[j].left<=erfen && zifuchuan[j].right>=erfen){
                 if((zifuchuan[j].left+zifuchuan[j].right)/2==erfen){break;
        }}}


        if(bencii>bencij){

            if(xiangtong==0)ans+=zifuchuan[j].right-zifuchuan[j].left+1;
            zifuchuan[i].left+=bencij;
            j--;
            if(zifuchuan[i].left<=erfen && zifuchuan[i].right>=erfen){
                    if((zifuchuan[i].left+zifuchuan[i].right)/2==erfen)
            break;
        }

        }


    }
    cout<<ans;
    return 0;
}
