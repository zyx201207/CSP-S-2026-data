#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],s,ma,qian[200010];
int q,w=10;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //xianxieyidiangunmu
    for(int i=q;i<w;i++){
        if(q>w){
            q++;
        }
        else{
            w--;
        }
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];qian[i]=(qian[i-1] and a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma;
    }
    else if(m==n){
        int l=a[1] and a[2];
        for(int i=3;i<=n;i++){
            l=(l and a[i]);
        }
        cout<<l;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
                int l1[100001]={},t1=0,l3=0;
                while(a[i]!=0){
                    t1++;
                    l1[t1]=a[i]%2;
                    a[i]/=2;
                }
            for(int j=i+1;j<=n;j++){
                int l2[100001]={},t2=0;
                while(a[j]!=0){
                    t2++;
                    l2[t2]=a[j]%2;a[j]/=2;
                }int l=1;
                for(int k=1;k<=max(t1,t2);k++){
                    if(l1[k]==1 and l2[k]==1){
                        l3+=1*l;
                    }
                    l*=2;
                }
                if(l>ma)ma=l;
            }
        }
        cout<<ma;
    }
    else{
        //zhegezenmexiea
        //wozhendebuhuia
    }
    return 0;
}
//anweiyuzenmegaoa
//wandanlewohunfendouhunbudao[daku][daku]
//woyilijie.
//meiyoushijianle.
