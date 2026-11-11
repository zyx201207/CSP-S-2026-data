#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    long long d,x;
    char c;
}a[200005];
char b[20000005];
long long l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        a[i].d=l+1;
        l+=a[i].x;
        for(int j=a[i].d;j<=a[i].d+a[i].x-1;j++){
            b[j]=a[i].c;
            //cout<<b[j]<<" ";
        }
    }
    //cout<<l<<endl;
    for(int i=1;i<=(l+1)/2;i++){
        if(b[i]!=b[l-i+1])ans++;
    }
    cout<<ans;
    /*int mid=(l+1)/2;
    for(int i=1;i<=n;i++){
        if(a[i].d<=mid&&a[i].d+a[i].x-1>=mid&&a[i].x!=1){
            int v=a[i].x;
            a[i].x=mid-a[i].d+1;
            for(int j=n;j>=i+1;j--){
                a[j+1].d=a[j].d;
                a[j+1].x=a[j].x;
                a[j+1].c=a[j].c;
            }
            if(mid%2==0){
                a[i+1].d=mid+1;
                a[i+1].x=v-a[i].x;
            }
            else{
                a[i+1].d=mid+1;
                a[i+1].x=v-a[i].x-1;
            }
            a[i+1].c=a[i].c;
        }
    }
    int res=n;
    for(int i=1;i<=n+1;i++){
        if(a[i].d+a[i].x-1>mid){
            break;
        }
        long long ps=l-a[i].d+1;
        long long cnt=0;
        char nw=a[i].c;
        char str=a[i].x;
        while(a[res].d<=ps+str-1){
            if(a[res].c!=nw)cnt+=a[i].x;
            res++;
        }
        ans+=cnt;
        a[res].d=ps+str;
    }
    for(int i=1;i<=n+1;i++){
        cout<<a[i].d<<" "<<a[i].x<<"---";
    }
    cout<<endl;
    cout<<ans;
    */
    return 0;
}
