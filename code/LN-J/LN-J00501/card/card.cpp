#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    vector<int> v(10000);
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>v[i];
    }
    cout<<b<<' '<<v[0]<<' '<<a;
    return 0;
}
