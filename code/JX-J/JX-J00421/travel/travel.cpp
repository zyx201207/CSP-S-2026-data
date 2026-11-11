#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
int a[10]={0,0,0,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]=1;
    }else{
        for(int i=0;i<4;i++){
            cout<<a[i];
        }
        return 0;
    }
    string wz1="",wz2="";
    for(int i=0;i<s1.size()-1;i++){
        wz1+=s1[i];
        wz2+=s2[i];
    }
    if(wz1==wz2){
        a[1]=1;
    }else{
        for(int i=0;i<4;i++){
            cout<<a[i];
        }
        return 0;
    }
    char p1=s1[s1.size()-1];
    char p2=s2[s2.size()-1];
    int pp1=p1-'0';
    int pp2=p2-'0';
    if((pp1<=19&&pp2<=19)||(pp1>=20&&pp2>=20)){
        a[2]=1;
        if(pp1==pp2+1||pp1==pp2-1){
            a[3]=1;
        }else{
            for(int i=0;i<4;i++){
                cout<<a[i];
            }
            return 0;
        }
    }else{
        for(int i=0;i<4;i++){
            cout<<a[i];
        }
        return 0;
    }
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    return 0;
}

