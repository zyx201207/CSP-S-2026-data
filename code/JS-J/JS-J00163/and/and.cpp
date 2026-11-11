#include<bits/stdc++.h>
using namespace std;
ifstream fin("and.in");
ofstream fout("and.out");
int n,m;
int a[200005];
int solve(int i,int j){
    if(i==n){
       if(j==m){
           return 0;
       }
       else{
           return -1e9;
       }
    }
    int x=solve(i+1,j+1) and a[i];
    int y=solve(i+1,j);
    return max(x,y);
}
int main(){
    fin>>n,m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    fout<<solve(0,0);
}
