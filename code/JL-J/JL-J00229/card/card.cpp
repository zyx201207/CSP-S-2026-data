#include<iostream>
#include<sys/procfs.h>
#include<string>
#include<cmath>
using namespace std;
int arr[100005];
int list_[100005];
int m_l[100005];
int a[100005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    for(int k=0;k<m;k++){
            for(int i=1;i<=n;i++){
                arr[i]=0;
                list_[i]=0;
            }
        for(int i=1+k;i<=n;i++){
            int num;num=a[i];
            if(arr[num]==0){
                arr[num]++;
                list_[cnt]=num;
                cnt++;
            }else{
                int ans=0;int index_=0;
                for(int j=1;j<=cnt;j++){
                    if(list_[j]==num&&ans==0){
                        index_=j;
                        ans++;
                    }else if(list_[j]==num&&ans==1){
                        for(int q=index_;q<=cnt;q++){
                            list_[q]=0;
                        }cnt-=(cnt-index_);
                        list_[cnt]=num;
                        cnt++;
                    }
                }
            }
        }for(int i=1;i<=cnt;i++){
            m_l[list_[i]]++;
        }}
    }
    for(int i=1;i<=m;i++){
        cout<<m_l[i]<<" ";
    }
   return 0;
}

