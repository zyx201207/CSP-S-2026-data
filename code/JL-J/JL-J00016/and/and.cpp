#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
     int n,m,dess[1225],sans[1997],gaster=0,aqua=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>dess[i];

    }
    for(int i=0;i<n;i++){
        for(int i=0;i<m;i++){
            sans[i]+=dess[i+1]^dess[i];
        }

    }

    for(int i=0;i<n;i++){

    if(sans[i]>sans[i+1]){
        gaster+=sans[i];
    }
    }

    aqua+=(m-2)*6;
    if(aqua==0){
        aqua+=1;
    }
    cout<<gaster/5/aqua;





    return 0;
}

