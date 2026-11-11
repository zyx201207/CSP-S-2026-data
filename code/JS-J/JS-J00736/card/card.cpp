#include<bits/stdc++.h>
using namespace std;
int n,m;
int zhan[500005]={0};
int shu[300005]={0};
int a[500005];
int top=1;
void finder(int k){
    for(int i=1;i<top;i++){
        if(zhan[i]==k){
            top=i;
            for(int j=i;j<=n;j++){
                zhan[j]=0;
            }
            break;
        }
    }
    return ;
}
void play(int t){
    for(int i=t+1;i<=n;i++){
        finder(a[i]);
        zhan[top]=a[i];
        top++;
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        top=1;
        play(i-1);
        for(int i=1;i<top;i++){
            shu[zhan[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<shu[i]<<" ";
    }
	return 0;
}
