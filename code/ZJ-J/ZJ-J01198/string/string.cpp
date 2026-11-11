#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int N=2e5+7;
int n;
int a[N];
char c[N],c1[N],c2[N],tmpc[N];
int sum;
int a1[N],a2[N];
int tmp[N];
void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int mid=sum/2,sum2=0,i=1,j=1;
    for(i=1;i<=n;i++){
        sum2+=a[i];
        if(sum2>=mid){
            a1[i]=mid-sum2+a[i],c1[i]=c[i],i+=(sum2==mid);
            break;
        }
        a1[i]=a[i],c1[i]=c[i];
    }
    int ni=i;
    for(j=1;i<=n;j++,i++){
        if(i==ni&&sum2!=mid)
            tmp[j]=sum2-mid,tmpc[j]=c[i];
        else
			tmp[j]=a[i],tmpc[j]=c[i];
    }
    if(sum%2){
        tmp[1]--;
        if(!tmp[1]){
            for(int k=1;k<j-1;k++)
                tmp[k]=tmp[k+1],tmpc[k]=tmpc[k+1];
            j--;
        }
    }
    for(int k=1;k<j;k++)
        a2[k]=tmp[j-k],c2[k]=tmpc[j-k];
    int ans=0,x=a1[1],y=a2[1],lst=0;
    j=i=1;
    while(a1[i]&&a2[j]){
    	fprintf(stderr,"x:%lld y:%lld i:%lld j:%lld lst:%lld\n",x,y,i,j,lst);
        if(y>x){
            if(c1[i]!=c2[j])
                ans+=x-lst;
            lst=x,x+=a1[++i];
        }
        else if(y<x){
            if(c1[i]!=c2[j])
                ans+=y-lst;
            lst=y,y+=a2[++j];
        }
        else{
            if(c1[i]!=c2[j])
                ans+=y-lst;
            lst=y,y+=a2[++j],x+=a1[++i];
        }
    }
    cout<<ans;
    return ;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
    return 0;
}