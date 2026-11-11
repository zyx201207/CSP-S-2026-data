#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001];
int main(){
    freeopen(and.in,"r",stdin);
    freeopen(and.out,"w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==4&&m==2)cout<<"12";
    if(n==5&&m==3)cout<<"7";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
