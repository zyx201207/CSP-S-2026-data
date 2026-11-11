#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int rc1,rs1,rc2,rs2;
char ch1,ch2;
void change(char &ch1,char &ch2){
    if(ch1>ch2){
        swap(ch1,ch2);
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    rc1=(c1[0]-'0')*10+c1[1]-'0';
    rc2=(c2[0]-'0')*10+c2[1]-'0';
    rs1=(s1[0]-'0')*10+s1[1]-'0';
    rs2=(s2[0]-'0')*10+s2[1]-'0';
    ch1=s1[2];
    ch2=s2[2];
    //cout<<rc1<<" "<<rc2<<" "<<rs1<<" "<<ch1<<" "<<rs2<<" "<<ch2;
    if(rc1==rc2){
        cout<<1;
        if(rs1==rs2){
            cout<<1;
            change(ch1,ch2);
            if((ch1=='A' && ch2== 'B') || (ch1=='B' && ch2== 'C') || (ch1=='D' && ch2== 'F')) cout<<11<<'\n';
            else if((ch1 == 'A' && ch2 =='C')) cout<<10<<'\n';
            else cout<<0<<0<<'\n';

        }
        else cout<<0<<0<<0<<'\n';
    }
    else cout<<0<<0<<0<<0<<'\n';
    return 0;
}
