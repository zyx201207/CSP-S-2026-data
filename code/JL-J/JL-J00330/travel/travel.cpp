#include<bits/stdc++.h>;
using namespace std;
typedef long long ll;

int c1,c2;
string sa,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c1>>sa>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string s3=sa.substr(0,2),s4=s2.substr(0,2);
        if(s3==s4){
            cout<<1;
            char lr=sa[2],lx=s2[2];
            int wa=lr-'A',wb=lx-'A';

            if((wa==3&&wb==5) || (wa==5&&wb==3)){
                cout<<11;
            }else if((wa>=0&&wa<=2) && (wb>=0&&wb<=2)){
                cout<<1;
                int cha = wa-wb;
                if(cha==1 || cha==-1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }

        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }


    return 0;
}
