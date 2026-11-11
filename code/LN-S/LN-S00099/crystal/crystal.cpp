#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],b[N];
int n,m;
int check(int k,int value){
    int m3=m;
    for(int i=k;i>=1;i--){
        if(m3-(a[k]-a[i])>=0){
            value++;
            m3-=(a[k]-a[i]);
        }else{
            break;
        }
    }
    return value;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag1=true;
    bool flag2=true;
    int cha=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cha=a[2]-a[1];
        if(a[i]!=a[i-1]+1){//特殊性质A的检测
            flag1=false;
        }
        if(i>=3){//特殊性质2的检测
            if(a[i]-a[i-1]!=cha){
                flag2=false;
            }
        }
    }

    sort(a+1,a+n+1);//排序，用来使二分，单调递增枚举

    if(flag1==true){//特殊性质A，O（N）
        int ans1=0;
        int mm=m;
        int j=-1;//代价
        for(int i=n;i>=1;i--){
            j++;
            if(mm-j>=0){
                ans1++;
                mm=mm-j;
            }else{
                cout<<ans1;
                return 0;
            }
        }
    }else if(flag2==true){//特殊性质B O(n)
        int ans3=0;
        int m2=m;
        int jj=-cha;
        for(int i=n;i>=1;i--){
            jj+=cha;
            if(m2-jj>=0){
                ans3++;
                m2-=jj;
            }else{
                cout<<ans3;
                return 0;
            }
        }
    }else if(n<=16&&m<=1000){//1~5 数据 O（n^2)
        int sum=0;
        for(int i=1;i<=n;i++){
            int mmm=m;
            int ans2=0;
            for(int j=i;j>=1;j--){
                if(mmm-(a[i]-a[j])>=0){
                    mmm-=(a[i]-a[j]);
                    ans2++;
                }else{
                    break;
                }
            }
            sum=max(sum,ans2);
        }
        cout<<sum;
    }else {//所有数据 O（n log n)
        int l=0,r=n;
        int ansmax=0;
        while(l<=r){
            int mid=(l+r)/2;
            int hanshuzhi=check(mid,1);
            if(hanshuzhi>=ansmax){
                ansmax=hanshuzhi;
                l=mid+1;
            }else {
                r=mid-1;
            }
        }
        cout<<ansmax;
    }
    return 0;
}
