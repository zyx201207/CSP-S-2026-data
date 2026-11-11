#include<bits/stdc++.h>
using namespace std;
int a[500010];
int t[500010];
int c[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool f=1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        cout << n;
    }
    if(m == 2){
        int q1=0,q2=0;
        for(int i = 1;i <= n;i++){
            if(a[i]==1&&a[n]==1){
                q1++;
            }
            else if(a[i]==2&&a[n]==2){
                q2++;
            }
            else{
                q1++;
                q2++;
            }
        }
        cout << q1 << " " << q2;
        return 0;
    }
    if(m == 3){
        int q1=0,q2=0,q3=0;
        for(int i = 1;i <= n;i++){
            if(a[i]==1&&a[n]==1){
                q1++;
            }
            else if(a[i]==2&&a[n]==2){
                q2++;
            }
            else if(a[i]==3&&a[n]==3){
                q3++;
            }
            else if(a[i]==1&&a[n]==3||a[i]==3&&a[n]==1){
                q1++;
                q3++;
            }
            else if(a[i]==2&&a[n]==3||a[i]==3&&a[n]==2){
                q2++;
                q3++;
            }
            else if(a[i]==1&&a[n]==2||a[i]==2&&a[n]==1){
                q1++;
                q2++;
            }
        }
        if(q1!=0){
            cout<<q1<<" ";
        }
        if(q2!=0){
            cout<<q2<<" ";
        }
        if(q3!=0){
            cout << q3<<" ";
        }
        return 0;
    }
    int nn = 1;
    while(nn <= n){
        int tt = 1;
        for(int i = nn;i <= n;i++){
            if(a[i]==a[i-1]){
                continue;
            }
            else{
                t[tt]==a[i];
                tt++;
                c[a[i]]++;
            }
        }
        nn++;
    }
    for(int i = 1;i <= n;i++){
        if(c[i]!=0){
            cout << c[i] << " ";
        }
    }
    return 0;
}
