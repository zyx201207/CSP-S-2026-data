#include<bits/stdc++.h>
using namespace std;
//100 pts
struct ops{
    char c;
    long long num;
};
long long n,ans;
ops a[200003],pre[200003];
/*
char find(int l,int r,int x){
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(pre[mid].num>=x){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return pre[ans].c;
}
*/
int main(){
    //add
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    //delete

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].num >> a[i].c;
        //pre[i].num=pre[i-1].num+a[i].num;
        //pre[i].c=a[i].c;
    }
    for(long long i=1,j=n;i<=j;){
        if(a[i].c==a[j].c){
            if(a[i].num>a[j].num){
                a[i].num=a[i].num-a[j].num;
                j--;
            }else if(a[i].num<a[j].num){
                a[j].num=a[j].num-a[i].num;
                i++;
            }else{
                i++;
                j--;
            }
        }else{
            if(a[i].num>a[j].num){
                ans+=a[j].num;
                a[i].num=a[i].num-a[j].num;
                j--;
            }else if(a[i].num<a[j].num){
                ans+=a[i].num;
                a[j].num=a[j].num-a[i].num;
                i++;
            }else{
                ans+=a[i].num;
                i++;
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}
