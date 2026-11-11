#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200007],a1[200007];
char c[200007],c1[200007];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0,ans=0,mid;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
    if(cnt%2==0)mid=cnt/2;
    else mid=cnt/2+1;
    int cnt1=0,num=0,numm,cn=0;
    for(int i=n-1;i>=0;i--){
        cnt1+=a[i];
        if(cnt1<mid){
            a1[num]=a[i];
            c1[num]=c[i];
            cn=cnt1;
            //cout<<"1"<<" "<<num<<" "<<a1[num]<<" "<<c1[num]<<endl;
            num++;
        }else if(cnt>=mid){
            a1[num]=mid-cn;
            c1[num]=c[i];
            a[i]=cnt1-mid;
            //cout<<"2"<<" "<<num<<" "<<a1[num]<<" "<<c1[num]<<" "<<cn<<endl;
            break;
        }
    }
    int cntt=0;
    for(int i=0,j=0;i<n,j<=num;){
        if(a1[j]>a[i]){
            if(c[i]!=c1[j])ans+=a[i];
            a1[j]-=a[i];
            //cout<<"j"<<i<<" "<<j<<" "<<c[i]<<c1[j]<<" "<<ans<<endl;
            i++;
        }else{
            if(c[i]!=c1[j])ans+=a1[j];
            a[i]-=a1[j];
            //cout<<"i"<<i<<" "<<j<<" "<<c[i]<<c1[j]<<" "<<ans<<endl;
            j++;
        }
    }
    if(cnt%2==0)cout<<ans;
    else cout<<ans-1;
    return 0;
}
/*
3
2 a
2 b
1 c*/
