#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int cx1,cx2,p1,p2;
    char l1,l2;
    cx1=(c1[0]-'0')*10+(c1[1]-'0');
    cx2=(c2[0]-'0')*10+(c2[1]-'0');
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    l1=s1[2];
    l2=s2[2];
    if(cx1==cx2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if('A'<=l1&&l1<='C'&&'A'<=l2&&l2<='C')cout<<1;
    else if('D'<=l1&&l1<='F'&&'D'<=l2&&l2<='F')cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(l2==(l1-1)||l2==(l1+1)){
        cout<<1;
    }else{
        cout<<0;
    }
	return 0;
}
