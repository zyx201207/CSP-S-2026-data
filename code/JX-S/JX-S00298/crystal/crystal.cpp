# include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,chaozuo,d,k,h,j;
    ll maix=1000000005;
    ll m[maix];
    ll chazhi[n];
    cin>>n>>chaozuo;
    while(n--){
        cin>>k;
        m[n]=k;
    }
    sort(m+1,m+n+1);
    while(n--){
        h=n-1;
        chazhi[h]=m[n]-m[h];
    }
    sort(chazhi+1,chazhi+n+1);
    for(int g=0;g<=n-1;g++){
        chaozuo=j;
        j=chaozuo-chazhi[g];
        if(chaozuo-chazhi[g]<0 || chaozuo-chazhi[g-1]>0){
            g=g-1;
            g=d;
        }

    }
    cout<<d;
return 0;
}

