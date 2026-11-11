#include<bits/stdc++.h>
using namespace std;
int c[750000];
int d[750000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int x=1;x<=b;x++){
        int n=0;
        for(int s=0;s<a;s++){
            for(int i=s;i<a;i++){
                d[i]=c[i];
                for(int j=0;j<i;j++){
                    if(d[i]==d[j]){
                        for(int k=j;k<=i;k++){
                            d[k]=0;
                        }
                        d[i]=c[i];
                    }
                }
            }
            for(int h=s;h<a;h++){
                if(d[h]==x){
                    n++;
                }
            }
        }
        cout<<n<<' ';
    }
    return 0;
}
