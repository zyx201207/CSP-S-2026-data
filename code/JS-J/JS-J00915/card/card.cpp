#include<bits/stdc++.h>
using namespace std;
int nlist[500005];
int save[500005];
int cnt[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nlist[i];
    }

    for(int i=0;i<n;i++){
        bool isin[300005]={false};
        int number=0;
        int del=0;

        for(int j=i;j<n;j++){

            if(isin[nlist[j]]){
                int ind=0;
                while(save[ind]!=nlist[j]&&ind<n) ind++;
                for(int x=ind;x<=number;x++) save[x]=0;
            }
            save[number]=nlist[j];
            isin[nlist[j]]=1;
            number++;
        }

        for(int k=del;k<number;k++){
            cnt[save[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }


    return 0;
}

