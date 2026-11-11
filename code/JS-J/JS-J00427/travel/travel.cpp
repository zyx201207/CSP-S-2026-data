#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int cnt=0;
    int n=max(c1.size(),c2.size());
    for(int i=0;i<n;i++){
        if(c1[i]==c2[i])cnt++;
    }
    if(cnt==n){
        a[1]=1;
        int c=0,cn=0;
        int x;
        int n1=max(s1.size(),s2.size());
        for(int i=0;i<n1;i++){
            if(s1[i]>='A'&&s2[i]<='F'){
                x=i;
                break;
            }
            cn++;
            if(s1[i]==s2[i])c++;
        }
        if(cn==c){
            a[2]=1;
            char q=s1[x];
            char w=s2[x];
            if(q<='C'&&w<='C'||q>='D'&&w>='D'){
                a[3]=1;

                if(q=='C'&&w=='D'||q=='D'&&w=='C')a[4]=0;
                else if((int)q+1==w||(int)q-1==w)a[4]=1;
            }else{
                a[3]=0;
                a[4]=0;
            }

        }else{
            a[2]=0;
            a[3]=0;
            a[4]=0;
        }
    }else{
        a[1]=0;
        a[2]=0;
        a[3]=0;
        a[4]=0;
    }
    for(int i=1;i<=4;i++)cout<<a[i];
    return 0;
}
