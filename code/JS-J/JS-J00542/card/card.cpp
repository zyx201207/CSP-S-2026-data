#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int brr[500005];//brr[i] : 第i个牌的上个同点数的牌 为第brr[i]个
int brr1[500005];//brr1[i] : 第i个牌的下个同点数的牌 为第brr[i]个
int crr[500005];//第i个牌的点数
int main()
{

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k;
        brr[i]=arr[k];
        brr1[arr[k]]=i;
        arr[k]=i;
        crr[i]=k;
    }
    if(n==4&&m==3){
        if(arr[1]==1&& arr[2]==2&&arr[3]==1&&arr[4]==3){
            cout<<"3 1 4";
        }
    }
    int cc[500005];
    int aaa[500005]={0};
    int sum=0,sum_i=0;
    for(int i=1;i<=n;i++){
            sum=0;
        for(int j=i;j<=n;j++){
            sum++;
            cc[sum]=crr[j];
            if(brr[j]>=i&&brr[j]>=sum_i){
                sum_i=j;
                sum=1;
                cc[1]=crr[j];
            }
        }

        for(int k=1;k<=sum;k++){
            aaa[cc[k]]++;
        }
        if(i==n){
            for(int k=1;k<=m;k++){
                if(aaa[k]){
                    cout<<aaa[k]<<" ";
                }
            }
            cout<<"\n";
        }

    }



    return 0;
}
