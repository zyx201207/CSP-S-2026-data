#include<bits/stdc++.h>
using namespace std;
int n;
long long len=0;
char temp,temp1;
long long ans=0;
bool falg=true;
struct sj{
    int a;
    char c;
};
sj x[200005];
int fun(sj m,sj n){
    return m.a<n.a;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].a>>x[i].c;
        len+=x[i].a;
    }
    for(int i=1;i<n;i++){
        temp=x[i].c;
        temp1=x[i+1].c;
        if(temp!=temp1){
            falg=false;
        }
    }
    sort(x,x+n,fun);
    if(falg==true){
        cout<<"0";
    }
    else if(len%2==0){
        for(int i=2;i<=n;i++){
            if(x[i].c!=x[1].c){
                ans+=x[i].a;
            }
        }
        cout<<ans;
    }
    else{
        for(int i=2;i<=n;i++){
            if(x[i].c!=x[1].c){
                ans+=x[i].a;
            }
        }
        cout<<ans-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
