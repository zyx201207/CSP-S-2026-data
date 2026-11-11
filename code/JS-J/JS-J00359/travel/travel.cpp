#include<bits/stdc++.h>
using namespace std;
int chexiang1,chexiang2;
int h1,h2;
char hao1,hao2;
string zuowei1,zuowei2;
bool is1,is2,is3,is4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>chexiang1>>zuowei1>>chexiang2>>zuowei2;
    for(int i=0;i<=1;i++){
        h1=h1*10+(zuowei1[i]-'0');
        h2=h2*10+(zuowei2[i]-'0');
    }
    hao1=zuowei1[2];
    hao2=zuowei2[2];
    if(chexiang1==chexiang2){
        is1=1;
        if(h1==h2){
            is2=1;
            if(hao1<='C'&&hao2<='C'){
                is3=1;
                if((int)hao1-hao2<=1&&(int)hao2-hao1<=1){
                    is4=1;
                }
            }
            if(hao1>'C'&&hao2>'C'){
                is3=1;
                is4=1;
            }
        }
    }
    cout<<is1<<is2<<is3<<is4<<endl;
    return 0;
}
