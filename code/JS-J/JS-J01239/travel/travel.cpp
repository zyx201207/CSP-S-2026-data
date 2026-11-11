#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
inline bool sameside(char a,char b){
    return (a<'D'&&b<'D')||(a>='D'&&b>='D');
}
inline bool near(char a,char b){
    if(a>b)swap(a,b);
    return b-a==1||(a=='D'&&b=='F');
}
int main(){
    #ifndef PSD
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool scage=(c1==c2),
        srol=scage&&s1.substr(0,2)==s2.substr(0,2),
        sside=srol&&sameside(s1.back(),s2.back()),
        nr=sside&&near(s1.back(),s2.back());
    cout<<scage<<srol<<sside<<nr;
    return 0;
}
