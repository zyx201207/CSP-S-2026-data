#include<bits/stdc++.h>
using namespace std;
//100 pts
string aa,ab,ba,bb;
int vis[256];
int main(){
    //add
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    //delete

    vis['A']=1;
    vis['B']=1;
    vis['C']=1;
    vis['D']=2;
    vis['F']=2;
    cin >> aa >> ab >> ba >> bb;
    if(aa==ba){
        cout << 1;
    }else{
        cout << 0;
    }

    if((aa==ba)&&(ab[0]==bb[0])&&(ab[1]==bb[1])){
        cout << 1;
    }else{
        cout << 0;
    }

    if((aa==ba)&&(ab[0]==bb[0])&&(ab[1]==bb[1])&&(vis[ab[2]]==vis[bb[2]])){
        cout << 1;
    }else{
        cout << 0;
    }

    if((aa==ba)&&(ab[0]==bb[0])&&(ab[1]==bb[1])&&(((vis[ab[2]]==2)&&(vis[ab[2]]==vis[bb[2]]))||((vis[ab[2]]==vis[bb[2]])&&((ab[2]-bb[2]==1)||(ab[2]-bb[2]==-1))))){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
