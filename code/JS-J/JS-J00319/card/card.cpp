#include<bits/stdc++.h>
using namespace std;
int m,n;
unsigned long long ans[300005];
int pai[300005];
int now[300005];
int p,k,q,r,t,z=0,x;
bool jum;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> pai[i];
    }
    for(int i=0;i<n;i++){
        now[0]=0;
        for(int j=0;j<n-i;j++){
            p=pai[i+j];
            k=0;
            jum=true;
            while(1){
                q=now[k];
                if(q==0)break;
                if(q==p&&jum){
                    jum=false;
                    now[k]=0;
                    break;
                }
                k++;
            }
            // cout << k <<'|';
            now[k]=p;
            now[k+1]=0;
        // }
            // for(x=0;x<n;x++){
            //     if(now[x]==0)break;
            //     cout << now[x] << ' ';
            // }
            // if(x==0)cout<<"(empty)";
            // // cout << endl << i << ' ' << j;
            // cout << endl;
        }
        z=0;
        while(1){
            t=now[z];
            if(t==0)break;
            ans[t]++;
            z++;
        }
        // for(z=1;z<m+1;z++){
        //     cout << ans[z] << ' ';
        // }
        // cout << endl << endl;
        now[n-i-1]=0;
    }
    for(int i=1;i<m+1;i++){
        cout << ans[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}