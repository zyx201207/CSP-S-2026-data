#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    int s1=0,s2=0,s3=0,s4=0;
    int n=c.size();
    int m=0,j=0;
    for(int i=0;i<n;i++){
        if(c[i]>='0'&&c[i]<='9'){
            int q=1;
            for(int j=1;j<n-1-i;j++){
                q*=10;
            }

            m+=(int(c[i]-'0'))*q;
        }
        if(d[i]>='0'&&d[i]<='9'){
            int q=1;
            for(int j=1;j<n-1-i;j++){
                q*=10;
            }

            j+=(int(d[i]-'0'))*q;
        }
        if(c[i]=='A'&&d[i]=='B'){
            s3=1;
            s4=1;
        }
        else if((c[i]=='B'&&d[i]=='A')||(c[i]=='B'&&d[i]=='c')){
            s3=1;
            s4=1;
        }
        else if(c[i]=='C'&&d[i]=='B'){
            s3=1;
            s4=1;
        }
        else if(c[i]=='D'&&d[i]=='E'){
            s3=1;
            s4=1;
        }
        else if(c[i]=='E'&&d[i]=='D'){
            s3=1;
            s4=1;
        }
        else if((c[i]=='A'&&d[i]=='C')||(c[i]=='C'&&d[i]=='A')){
            s3=1;
        }

    }
    if(m==j){
        s2=1;
    }
    else{
        s3=0;
        s4=0;
    }
    if(a==b){
        s1=1;
    }
    else{
        s2=0;
        s3=0;
        s4=0;
    }
    cout<<s1<<s2<<s3<<s4;
    return 0;
}
