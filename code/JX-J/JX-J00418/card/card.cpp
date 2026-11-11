#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+10;
struct ddd{
    long long s;
    bool st;
}a[N];
long long t[N];
long long temp_t[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[j].st = 1;
        }
        memset(temp_t,0,sizeof(temp_t));
        for(int j=i;j<=n;j++){
            if(temp_t[a[j].s]==0){
                temp_t[a[j].s]++;
            }
            else{
                bool f = 0;
                //find
                for(int k=1;k<j;k++){
                    if(a[k].s == a[j].s&&a[k].st == 1){
                        /*
                        cout<<"j: "<<j<<"\n";
                        for(int j=1;j<=m;j++){
                            cout<<temp_t[j]<<" ";
                        }
                        cout<<"\n";
                        */
                        f = 1;
                    }
                    if(f&&temp_t[a[k].s]>0&&a[k].st == 1){
                        temp_t[a[k].s]--;
                        a[k].st = 0;
                    }
                }
                temp_t[a[j].s]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(temp_t[j]!=0){
                t[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }


    return 0;
}
