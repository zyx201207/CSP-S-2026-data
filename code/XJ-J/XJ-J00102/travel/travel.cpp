#include <bits/stdc++.h>
using namespace std;
bool side(char c){
    return c>='D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string acar,aseat,bcar,bseat;
    cin>>acar>>aseat>>bcar>>bseat;
    bool flag=1;
    cout<<(flag=flag&&acar==bcar)<<(flag=flag&&aseat[0]==bseat[0]&&aseat[1]==bseat[1])<<(flag=flag&&side(aseat[2])==side(bseat[2]))<<(flag=flag&&(aseat[2]-bseat[2]==1||aseat[2]-bseat[2]==-1))<<'\n';
    return 0;
}