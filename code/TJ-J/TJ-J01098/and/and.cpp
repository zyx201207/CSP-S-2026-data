#include<iostream>
using namespace std;
int a[200005],aa[200005],aaa[200005],c=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        aa[i]=a[i];
        aaa[i]=a[i];
    }
    if(m==1){
        int manx=-1;
        for(int i=1;i<=n;i++){
            if(a[i]>=maxn){
                maxn=a[i];
            }
        }
        cout<<maxn;
    }
    else{
            for(int i=1;i<=n;i++){
            	c=1;
                while(a[i]>=1){
                        if(a[i]%2==1){
                        	aa[i]+=c;
						}
						a[i]/=2;
						c*=10;
            }
            if(m=2){
                int maxn=0;
                for(int i=1;i<=n;i++){
                    for(int i=1;i<=n;i++){

                    }
                }
            }
    }
    return 0;
}
