#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[200005]={};
    long long b[200005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long sum=-1;
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>sum){
                sum=a[i];
            }
        }
        cout<<sum;
        return 0;
    }
fclose(stdin);
fclose(stdout);

    return 0;
}


