#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int is1,is2;
    cin>>c1>>is1>>s1>>c2>>is2>>s2;
    if(c1==c2){
        cout<<1;
        if(is1==is2){
            cout<<1;
            if(s1=="A"||s1=="B"||s1=="C"){
                if(s2=="A"||s2=="B"||s2=="C"){
                    cout<<1;
                    if(s1=="B"||s2=="B"){
                        cout<<1;
                    }
                    else cout<<0;
                }
                else cout<<0<<0;
            }
            else if(s1=="D"||s1=="F"){
                if(s2=="D"||s2=="F"){
                    cout<<11;
                }
                else cout<<0<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
