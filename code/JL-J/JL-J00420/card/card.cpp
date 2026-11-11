#include<bits/stdc++.h>
using namespace std;

int t[1000000];
int u[1000000];
struct f{
    int s;
    int c;
};

f a[1000000];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i].s;
        a[i].c=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                         u[a[j].s]=1;
        t[a[j].s]++;
        if(t[a[j].s]>1){

                t[a[j].s]=1;

            for(int ij=j-1;ij>=i;ij--){
                u[a[ij].s]=0;

            }
            u[a[j].s]=1;
        }

        }
        for(int ij=1;ij<=m;ij++)
            cout << u[ij] << ' ';
cout << endl;
        for(int j=1;j<=m;j++){
                t[j]=0;

            if(u[j])
                a[j].c++;
                u[j]=0;
        }

    }
    for(int j=1;j<=m;j++)
        cout << a[j].c << ' ';
    return 0;
}

