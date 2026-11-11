#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c1,c2,a[4],t1=0,t2=0;
char s1,s2,p1,q1,p2,q2;

int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    cin>>c1>>p1>>q1>>s1;
    cin>>c2>>p2>>q2>>s2;
    if(s1=='A'||s1=='B'||s1=='C')t1=1;
    if(s2=='A'||s2=='B'||s2=='C')t2=1;
    if(c1==c2){
        a[0]=1;
        if(p1==p2&&q1==q2){
            a[1]=1;
            if(t1==t2){
                a[2]=1;
                if(t1==1&&(s1-s2==1||s1-s2==-1)){
                    a[3]=1;
                }
                else if(t1==0) a[3]=1;
            }
        }
    }
    for(int i=0;i<=3;i++){
        cout<<a[i];
    }
    return 0;
}
