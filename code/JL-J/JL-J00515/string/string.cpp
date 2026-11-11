#include<bits/stdc++.h>
using namespace std;
int n,m;
char t;
long long cnt;
long long sum;
string s;
struct node{
    int longg;
    char zimu;
}poin[200010],poin2[200010];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        getchar();
        cin>>t;
        sum+=m;
        poin2[i].longg=m;
        poin2[i].zimu=t;
    }
    long long nsum=0,pos1=0,pos2=0;
    for(int i=0;i<n;i++){
        poin[i]=poin2[i];
        nsum+=poin[i].longg;
        if(nsum>sum/2){
            if(sum%2==1){
                pos1=i;
                pos2=i+2;
            }else{
                pos1=i;
                pos2=i+1;
            }break;
        }
    }
    int wei;
    if(pos2-pos1==1){
        poin[pos1].longg=(sum/2)-nsum+poin[pos1].longg;
        poin[pos2].longg=nsum-sum/2;
        poin[pos2].zimu=poin[pos1].zimu;
        wei=1;
    }else{
        poin[pos1].longg=(sum/2)-nsum+poin[pos1].longg;
        poin[pos1+1].longg=1;
        poin[pos1+1].zimu=poin[pos1].zimu;
        poin[pos2].longg=nsum-sum/2-1;
        poin[pos2].zimu=poin[pos1].zimu;
        wei=2;
    }
    for(int i=pos1+1;i<n;i++){
        poin[i+wei]=poin2[i];
    }
    for(int i=0;i<n+wei;i++){
        cout<<poin[i].longg<<" "<<poin[i].zimu<<endl;
    }
    cout<<pos1<<" "<<pos2;
    nsum=sum;
    long long l=0;
    while(nsum>0){
        if(poin[pos1].longg==0){
            pos1--;
        }
        if(poin[pos2].longg==0){
            pos2--;
        }
        int minn=min(poin[pos1].longg,poin[pos2].longg);
        if(poin[pos1].zimu!=poin[pos2].zimu)
        cnt+=minn;
        poin[pos1].longg-=minn;
        poin[pos2].longg-=minn;
        nsum-=2*minn;
    }
    cout<<cnt;
}

