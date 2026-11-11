#include<iostream>
#include<string>
using namespace std;
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
int main(){
    init();
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;
        int c=int(s1[0]-'0')*10+int(s1[1]-'0'),d=int(s2[0]-'0')*10+int(s2[1]-'0');
        if(c==d){
            cout<<1;
            if(((s1[2]<'D')&&(s2[2]<'D'))||((s1[2]>='D')&&(s2[2]>='D'))){
                cout<<1;
                if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
