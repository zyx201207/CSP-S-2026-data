#include<bits/stdc++.h>
using namespace std;
long long n,m,card[500001],cnt[500001];
int isontb(int i,int j,bool tb[n+10]){
    for(int p=i;p<=j-1;p++){
        if((card[p]==card[j])&&tb[p]){
            return p;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        bool ontb[n+10];//on table
        memset(ontb,0,sizeof(ontb));
        for(int j=i;j<=n;j++){
            int k=isontb(i,j,ontb);
            if(k){
                for(int q=k;q<=j;q++){
                    ontb[q]=0;
                }
                ontb[j]=1;
            }else{
                ontb[j]=1;
            }
        }
        for(int j=i;j<=n;j++){
            if(ontb[j]){
                cnt[card[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
