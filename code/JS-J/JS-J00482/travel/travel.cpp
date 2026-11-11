#include<bits/stdc++.h>
using namespace std;
int n,m,aa,aaa,bb,bbb;
string stra,strb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>stra>>m>>strb;
    aa=stra[0];
    bb=strb[0];
    aaa=stra[1];
    bbb=strb[1];
    if(n!=m)  cout<<0<<0<<0<<0;
    else{
        if(aa!=bb||aaa!=bbb) cout<<1000;
        else{
            if(stra[stra.size()-1]<=67&&strb[strb.size()-1]>67) {
                    cout<<1100;
                    return 0;
            }
            else{
                if(stra[stra.size()-1]+1!=strb[strb.size()-1]&&strb[strb.size()-1]+1!=stra[stra.size()-1]){
                        cout<<1110;
                        return 0;
                }
                else {
                        cout<<1111;
                        return 0;
                }
            }
            if(stra[stra.size()-1]>67&&strb[strb.size()-1]<=67)
                    cout<<1100;

            else{
                if(stra[stra.size()-1]-1!=stra[stra.size()-1]&&strb[strb.size()-1]+1!=stra[stra.size()-1])cout<<1110;
                else cout<<1111;
            }
        }
    }




    return 0;
}
