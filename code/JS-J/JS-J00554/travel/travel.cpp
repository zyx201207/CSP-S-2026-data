#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    long long sum1=(s1[0]-'0')*10+(s1[1]-'0'),sum2=(s3[0]-'0')*10+(s3[1]-'0');
    long long cnt1=(s2[0]-'0')*10+(s2[1]-'0'),cnt2=(s4[0]-'0')*10+(s4[1]-'0');
    char c1=s2[2],c2=s4[2];
    bool flag=false;
    if(sum1==sum2){
        cout<<1;
        if(cnt1==cnt2){
            cout<<1;
            if(c1=='A'||c1=='B'||c1=='C'){
                if(c2=='A'||c2=='B'||c2=='C'){
                    flag=true;
                    cout<<1;
                    if(c1+1==c2||c1-1==c2){
                        cout<<1;
                    } else {
                        cout<<0;
                    }
                }
            }
            else if(c1=='D'||c1=='F'){
                if(c2=='D'||c2=='F'){
                    cout<<1;
                    flag=true;
                    if(c1+1==c2||c1-1==c2){
                        cout<<1;
                    } else {
                        cout<<0;
                    }
                }
            }
            if(flag==0){
                cout<<0<<0;
            }
        } else {
            cout<<0<<0<<0;
        }
    }else {
        cout<<0<<0<<0<<0;
    }
    return 0;

}
