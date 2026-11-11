#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<b;i++) cout<<(i%2)+1<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
