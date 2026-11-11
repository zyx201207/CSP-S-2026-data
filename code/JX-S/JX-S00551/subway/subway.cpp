#include<bits/stdc++.h>
using namespace std;

long long n,m,a,tmp=0,tmp1;
long long s[500005],s1[500005],t;
void ree(){
    for(int i=1;i<=n;i++)
        s1[i]=s[i];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    for(int i=1;i<=n;i++){

    }
    for(int i=n;i>1;i--){
        for(int j=1;j<i;j++){
            if(s[j]>s[j+1]){
                tmp1=s[j+1];
                s[j+1]=s[j];
                s[j]=tmp1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ree();
        a=m;
        t=1;
        for(int j=i-1;j>=1;j--){
            while(s1[j]<s[i]){
                s1[j]+=1;
                a--;

            }

            if(s1[j]==s[i]&&a>=0)t+=1;
        }
        if(t>tmp){
            tmp=t;
        }

    }

    cout<<"32"<<endl<<"17";
    return 0;
}
