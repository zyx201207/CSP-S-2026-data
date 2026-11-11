#include<bits/stdc++.h>
using namespace std;
int sj[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=0,o=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sj[i];
    }
    for(int i=1,s;i<=n;i++){
        for(int j=1;j<n;j++){
            if(sj[j]>sj[j+1]){
                s=sj[j];
                sj[j]=sj[j+1];
                sj[j+1]=s;
            }
        }
    }
    while(1){
        int c;
        c++;
        if((sj[c+1]-sj[c])*c<=m){
            for(int i=1;i<=c;i++){
               sj[i]=sj[c+1];
            }
            m=m-(sj[c+1]-sj[c])*c;
        }
        else{
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(sj[1]==sj[i]){
            o++;
        }
    }
    for(int i=1;i<=1;i++){
        cout<<o;
    }
    return 0;

    fclose(stdin);
    fclose(stdout);

}
