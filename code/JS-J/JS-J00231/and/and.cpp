#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N][40],max_cnt=0,max_and=0,a1[N],c=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long b,cnt=1;
        cin>>a1[i];
        b=a1[i];
        while(b!=1){
            a[i][cnt]=b%2;
            b/=2;
            cnt++;
        }
        a[i][cnt]=1;
        max_cnt=max(max_cnt,cnt);
    }
    for(int i=1;i<=n;i++){
        for(int j=max_cnt;j>=1;j--)
            cout<<a[i][j];
    cout<<endl;
    }
    for(int i=1;i<max_cnt;i++)
        c*=2;
    if(m==1)
        for(int i=1;i<=n;i++)
            max_and=max(max_and,a1[i]);
    else if(m==2)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j){
                    long long b=0,c1=c;
                    for(int k=max_cnt;k>=1;k--){
                        if(a[i][k]==1&&a[j][k]==1)
                            b+=c1;
                        c1/=2;
                    }
                    max_and=max(max_and,b);
                }
    else if(m==3)
        for(int d=1;d<=n;d++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(i!=j&&j!=d&&d!=i){
                        long long b=0,c1=c;
                        for(int k=max_cnt;k>=1;k--){
                            if(a[i][k]==1&&a[j][k]==1&&a[d][k]==1)
                                b+=c1;
                            c1/=2;
                        }
                        max_and=max(max_and,b);
                    }
    else if(m==4)
        for(int e=1;e<=n;e++)
            for(int d=1;d<=n;d++)
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if(i!=j&&j!=d&&d!=e&&j!=e&&d!=i&&i!=e){
                            long long b=0,c1=c;
                            for(int k=max_cnt;k>=1;k--){
                                if(a[e][k]==1&&a[i][k]==1&&a[j][k]==1&&a[d][k]==1)
                                    b+=c1;
                                c1/=2;
                            }
                            max_and=max(max_and,b);
                        }
    else
        for(int f=1;f<=n;f++)
            for(int e=1;e<=n;e++)
                for(int d=1;d<=n;d++)
                    for(int i=1;i<=n;i++)
                        for(int j=1;j<=n;j++)
                            if(i!=j&&j!=d&&d!=e&&j!=e&&d!=i&&i!=e&&i!=f&&j!=f&&d!=f&&e!=f){
                                long long b=0,c1=c;
                                for(int k=max_cnt;k>=1;k--){
                                    if(a[e][k]==1&&a[i][k]==1&&a[j][k]==1&&a[d][k]==1&&a[f][k]==1)
                                        b+=c1;
                                    c1/=2;
                                }
                            }
    cout<<max_and;
    return 0;
}
