#include<bits/stdc++.h>
using namespace std;
long long n,m,A[500005];
int qread(){
    int x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) {
        if(c=='-') f=-1;
    }
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
/*
int erfeng(long long x,){
    long long l=0,r=n+1;
    while(A[l]<A[r]){
        mid=(l+r)>>1;
        if(A[mid]>A[x]) r=mid;
        else l=mid;
    }
}
 */

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //int b=qread();
    //cout<<b;
    n = qread();m = qread();
    for(int i=1;i<=n;i++)
        A[i]=qread();
    sort(A+1,A+n+1);
    if(n>5000){
        long long numb=1,j=1;
        while(m>=0&&j<n){
            j++;
            m-=((j-1)*(A[j]-A[j-1]));
            if(m<0){
                j--;
                }

        }
        cout<<j;
    }
    else{
        long long numb=1,j1=0;
        int k=n;
        for(int i=1;i<=k;i++){
            int j=i,m1=m;
            while(m1>=0&&j<n){
                j++;
                m1-=((j-i)*(A[j]-A[j-1]));
                if(m1<0){
                    j--;
                    }
            }
            j=j-i+1;
            if(j>j1) j1=j;
            k=n-j1;
        }
        cout<<j1;
    }



    return 0;
}
