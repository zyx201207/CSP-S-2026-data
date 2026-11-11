#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopem("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;//preparation
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int point[m]={0};


    for(int l=0;l<n;l++){//n times
        int left=l; bool number[m]={0};
        for(int i=l;i<n;i++){//cards
            if(number[a[i]-1]){
                left=i;
            }else number[a[i]-1]=1;
        }
        for(int i=left;i<n;i++){
            point[a[i]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<point[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
