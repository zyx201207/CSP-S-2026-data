#include<bits/stdc++.h>
std::ifstream fin("card.in");
std::ofstream fout("card.out");
int main(){
    int n,m;
    fin>>n>>m;
    int a[n];
    long long sum[m+1]={0};
    for(int i=0;i<n;i++){
            fin>>a[i];
    }
    for(int i=0;i<n;i++){
        bool b[m]={false};
        int c[n];
        int x=0;
        for(int j=i;j<n;j++){
            if(b[a[j]]==true){
                int z=0;
                while(c[z]!=a[j]){
                    z++;
                }
                x=z;
                while(z<=j-i){
                    b[c[z]]=false;
                    c[z]=0;
                    z++;
                }
            }
            c[x]=a[j];
            b[a[j]]=true;
            x++;
        }
        for(int g=1;g<m+1;g++){
            if(b[g]){
                sum[g]++;
            }
        }
}
    for(int i=1;i<=m;i++){
        fout<<sum[i]<<" ";
    }
    return 0;
}
