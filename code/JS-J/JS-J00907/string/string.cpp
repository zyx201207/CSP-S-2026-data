#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],qz[N],cnt;
char ch[N];
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        qz[i]=a[i]+qz[i-1];

    }
    long long L=qz[n],mid=(qz[n]+1)/2;
    bool flag=0;
    for(long long i=mid;i>=1;i--){
        long long l=1,r=n,mid1;
        while(l<=r){
            mid1=l+(r-l)/2;
            if(qz[mid1]<i) l=mid1+1;
            else if(qz[mid1-1]>=i) r=mid1-1;
            else{
                flag=1;
                break;
            }
        }
        if(flag==0) mid1+=1;
        flag=0;
        long long rev_i=L+1-i,mid2;
        l=1,r=n;
        while(l<=r){
            mid2=l+(r-l)/2;
            if(qz[mid2]<rev_i) l=mid2+1;
            else if(qz[mid2-1]>=rev_i) r=mid2-1;
            else{
                flag=1;
                break;
            }
        }
        if(flag==0) mid2+=1;
        if(ch[mid1]!=ch[mid2]) cnt++;
        //cout<<mid1<<" "<<mid2<<endl;

    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
