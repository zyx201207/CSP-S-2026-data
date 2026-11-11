#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
vector<int>a,pr;
vector<char>c;
int n;
int fnd(int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(pr[m]>=x){
            r=m;
        }else{
            l=m+1;
        }
    }
    return l;
}
void fg(int x,int y){
    for(int i=n-1;i>x;i--){
        a[i]=a[i-1];
        c[i]=c[i-1];
    }
    for(int i=n;i>x;i--){
        a[i]=a[i-1];
        c[i]=c[i-1];
    }
    a[x+1]=1;
    a[x+2]=pr[x]-y;
    a[x]=pr[x]-1-a[x+1];
    c[x+1]=c[x];
    c[x+2]=c[x];
}
void fg2(int x,int y){
    for(int i=n;i>x;i--){
        a[i]=a[i-1];
        c[i]=c[i-1];
    }
    a[x+1]=pr[x]-y;
    a[x]-=a[x+1];
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    a.resize(n+5);
    pr.resize(n+5);
    c.resize(n+5);
    int L=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        if(i!=0){
            pr[i]=pr[i-1]+a[i];
        }else{
            pr[i]=a[i];
        }
    }
    int mid=(L+1)/2;
    int ans=0;
    if(L%2!=0){
        int w=fnd(mid);
        fg(w,mid);
        n+=2;
        for(int i=0,j=n-1;i<w&&j>w&&i<j-1;){
            if(a[i]>a[j]){
                if(c[i]!=c[j]){
                    ans+=a[j];
                }
                a[i]-=a[j];
                j--;
            }
            if(a[i]>a[j]){
                if(c[i]!=c[j]){
                    ans+=a[i];
                }
                a[j]-=a[i];
                i++;
            }
            if(a[i]==a[j]){
                if(c[i]!=c[j]){
                    ans+=a[j];
                }
                i++;j--;
            }
        }
    }else{
        int w=fnd(mid);
        fg2(w,mid);
        n++;
        for(int i=0,j=n-1;i<=w&&j>w;){
            if(a[i]>a[j]){
                if(c[i]!=c[j]){
                    ans+=a[j];
                }
                a[i]-=a[j];
                j--;
            }
            if(a[i]>a[j]){
                if(c[i]!=c[j]){
                    ans+=a[i];
                }
                a[j]-=a[i];
                i++;
            }
            if(a[i]==a[j]){
                if(c[i]!=c[j]){
                    ans+=a[j];
                }
                i++;j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
