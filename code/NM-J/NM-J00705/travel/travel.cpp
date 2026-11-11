#include<bits/stdc++.h>
using namespace std;
bool box=0,p=0,line=0,besides=0;
string ah1,ah2,bh1,bh2;
int main(){
    freopem("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ah1>>ah2>>bh1>>bh2;
    if(ah1==bh1){
        box=1;
        if(ah2[0]==bh2[0] && ah2[1]==bh2[1]){
            p=1;
            if(ah2[2]>=65 && ah2[2]<=67 && bh2[2]>=65 && bh2[2]<=67){
                line=1;
                if(ah2[2]-bh2[2]==1 || ah2[2]-bh2[2]==-1) besides=1;
            }else if(ah2[2]>67 && ah2[2]<=69 && bh2[2]>67 && bh2[2]<=69){
                line=1;
                if(ah2[2]-bh2[2]==1 || ah2[2]-bh2[2]==-1) besides=1;
            }
        }
    }
    cout<<box<<p<<line<<besides;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
