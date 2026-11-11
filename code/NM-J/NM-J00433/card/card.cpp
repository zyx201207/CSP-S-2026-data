#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,r=0;
    cin>>n>>m;
    vector<int>cardset(n);
    vector<int>cardputen(n);
    vector<int>remember(n);
    for(int i = 0;i<n;i++){
        cin>>cardset[i];
    }
    int x = n;
    while(x){
        int r = n;
        for(int i = 0;i<n;i++,r--){
            cardputen[r] = cardset[n];
            cardset[n] = (i==0?cardset:0);
            for(int j = 0;j<=i;j++){
                if(flag)cardputen[j]=0;
                if(j==i)break;
                else{
                    if(cardputen[j]==cardputen[i]){
                        flag = true;
                    }
                }
            }
            if(cardputen[i]=i)
            remember[i]++;
        }
        x--;
    }
    for(int i = 0;i<n;i++){
        if(remember[i])
            cout<<i<<" ";
    }
}
