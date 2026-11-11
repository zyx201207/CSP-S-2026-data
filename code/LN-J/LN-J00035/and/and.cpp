#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    unsigned long long a,mn;
    cin>>n>>m;
    cin>>mn;

    for(int i=1;i<n;i++){
        cin>>a;
        mn=(unsigned long long)(min(mn,a));
    }
    cout<<mn;
    fclose(stdin);
    fclose(stdout);
}
