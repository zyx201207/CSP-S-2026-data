#include<bits/stdc++.h>
using namespace std;
int n;
int flag=1;
long long ans=0;
int b[200005];
int c[200005];
string a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        cin>>a[i];
    }

    int q1=1,q2=n;
    int z=(n+1)/2;
    int z2=z+1;
    while(1){
        if(c[q1]>c[q2]){
            if(a[q1]!=a[q2]) ans+=c[q2];
            c[q1]-=c[q2];
            c[q2]=0;
            flag++;
            q2--;
        }else if(c[q1]<c[q2]){
            if(a[q1]!=a[q2]) ans+=c[q1];
            c[q2]-=c[q1];
            c[q1]=0;
            flag++;
            q1++;
        }else{
            if(a[q1]!=a[q2]) ans+=c[q1];
            c[q1]=0;
            c[q2]=0;
            flag+=2;
            q2--;
            q1++;
        }
            if(flag==n||flag==n+1){
                break;
            }
        }



    cout<<ans;
    return 0;
}

