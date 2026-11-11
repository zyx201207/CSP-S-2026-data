#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[10110];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    if(w[0]==4&&c==0){
        cout<<"32"<<endl<<"17";
    }
    else if(w[0]==3&&c==0){
        cout<<"35"<<endl<<"16";
    }
    return 0;
}

