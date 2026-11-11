#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int l,r;
    string name="crystal";
    cin>>l>>r;
    string std=name+".exe";
    string in,out,ans,str;
    for(char i='0'+l;i<='0'+r;i++){
        in=name+i+".in";
        out=name+i+".out";
        ans=name+i+".ans";
        str=std+" < "+in+" > "+out;
        system(str.c_str());
        str="fc "+out+" "+ans;
        if(system(str.c_str())){
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}