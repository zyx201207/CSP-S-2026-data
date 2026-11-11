#include<bits/stdc++.h>
using namespace std;
long long x,y,a[300000],b[200001][31],c[200001],d[200001],ans;
vector<int>v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%d%d",&x,&y);
    for(int i=0;i<x;i++){
        c[i]=1;
        scanf("%lld",&a[i]);
        long long p=a[i];
        while(p!=0){
            v.push_back(p%2);
            p=p/2;
        }
        for(int k=0,j=0;k<v.size();k++,j++){
            b[i][j]=v[k];
        }
        v.clear();
    }
    for(int i=30;i>=0;i--){
        for(int k=0;k<x;k++){
            if(b[k][i]==1){
                d[k]=1;
            }
        }
        int hf=0;
        for(int k=0;k<x;k++){
            if(d[k]==1 and c[k]==1){
                hf++;
            }
        }
        if(hf>=y){
            ans+=(long long)1<<i;
            for(int k=0;k<x;k++){
                if(d[k]==1 and c[k]==1){
                    c[k]=1;
                }
                else{
                    c[k]=0;
                }
                d[k]=0;
            }
        }
            for(int k=0;k<x;k++){

                d[k]=0;
            }
    }
    printf("%lld",ans);
    return 0;
}
