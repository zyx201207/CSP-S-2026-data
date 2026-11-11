#include<bits/stdc++.h>
int main(){
    int n,m={0};
    int a[n]={0};
    std::ifstream fin("and.in");
    std::ofstream fout("and.out");
    fin>>n>>m;
    for(int i=0;i<n;i++){
       fin>>a[i];
    }
    std::sort(a,a+n);
    int z=a[n-1];
    for(int i=2;i<=m;i++){
        z=i&a[n-i];
    }
    fout<<z;
}
