#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a,b;
    string c1,s1,c2,s2;
    cin>>c1>>a>>s1>>c2>>b>>s2;
    if(c1==c2){
        cout<<1;
        if(a==b){
                cout<<1;
                if('s1'>=65&&'s1'<67&&'s2'>=65&&'s2'<67||'s1'>67&&'s1'<=70&&'s2'>67&&'s2'<=70){
                    cout<<0;

                }else{
                    cout<<1;
                    if('s1'==67&&'s2'==68||'s2'==67&&'s1'==68){
                        cout<<1;
                    }else if('s1'+1=='s2'||'s1'-1=='s2'){
                        cout<<0;
                    }else{
                        cout<<1;
                    }
                }
                }else{
                    cout<<0;
                }
                    }else{
                        cout<<"0000";
                    }

                return 0;
}
