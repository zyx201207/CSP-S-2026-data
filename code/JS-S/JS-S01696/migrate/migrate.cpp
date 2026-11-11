#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,loc[N],n,d;
/*
int judge(int a,int b){
    int side[5005];
    for(int i=a;i<b;i++){
        if(loc[i+1]-loc[i]>d) return 0;
        for(int j=i+1;j<=b;j++){
            if(loc[j]-loc[i]>d) break;
            else side[i]++;
        }
    }

    int two=0;
    for(int i=a;i<=b;i++){
        if(side[i]>2 or two>1) return 0;
        else if(side[i]==2 and two<2) two++;
    }
    return 1;
}
*/
int judge(int a,int b){
    for(int i=a;i<b;i++){
        if(loc[i+1]-loc[i]>d) return 0;
    }
    int minn=N,cnt=1;
    for(int i=0;i<pow(2,b-a-1);i++){
        int p=i,m=0,flag=b;
        for(int j=b-1;i and j>a;b--){
            if(p&1){
                if((loc[flag]-loc[j])>d){
                    m=0;
                    break;
                }
                m++;
                flag=i;
            }
            p=(p>>1);
        }
        if(m<minn){
            minn=m;
            cnt=1;
        }
        else if(m==minn) cnt++;
    }
    if(cnt==2) return 1;
    else return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int s=0;
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>loc[j];
        }
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                s+=judge(k,l);
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
