#include <bits/stdc++.h>
using namespace std;
vector<int> w;
vector<int> a;
vector<int> t;
vector<int> tong;
vector<pair<int,int>> r;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    tong.resize(m+5);
    w.resize(m+5);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    int k;
    cin>>k;
    a.resize(2*k+5);
    t.resize(2*k+5);
    for(int i=1;i<=2*k;i++){
        int a1,t1;
        cin>>a1>>t1;
        a[i]=a1;
        tong[a1]++;
        t[i]=t1;
    }
    r.resize(q+5);
    for(int i=1;i<q;i++){
        int x1,y1;
        cin>>x1>>y1;
        r[i]={x1,y1};
    }
    //stdin
    for(int i=1;i<=m;i++){
        if(tong[i]>1){
            tong[i]=1;
        }
        else{
            tong[i]=0;
        }
    }


    int l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    while(q--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l1++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l2++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l3++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l4++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l5++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l6++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l7++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l8++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l9++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l10++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l1++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l2++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l3++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l4++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l1++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                l2++;
            }
        }

    }







    return 0;
}
