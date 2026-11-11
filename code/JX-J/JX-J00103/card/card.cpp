#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("card.in",r,stdin);
    //freopen("card.out",r,stdout);
    long long q,a,q1=0,q2=0;
    cin>>q>>a;
    long long z[q],z1[q],v[q];
    for(int i=0;i<q;i++){
        cin>>z[i];
    }
    for(int i=0;i<q;i++){
        q1=i;
        q2=i;
        while(1){
            bool w=0;
            for(int i=0;i<q;i++){
                if(z[i]!=0)w=1;
                if(i==q-1 && w==1)break;
            }
            q1++;
            q2++;
            z1[q1]=z[q2];
            z[q2]=0;
            for(int j=0;j<q1;j++){
                if(z1[j]==z[q1]){
                    z[q2]=z1[q1];
                    for(int k=0;k<=q1;k++){
                        z1[k]=0;
                    }
                }
            }
            z1[i]=z[q2];
            q1=i;
        }
        for(int j=0;j<q;j++){
            if(z1[j]!=0){
                v[z1[j]]++;
            }
        }
    }
    for(int i=1;i<a;i++){
        cout<<v[i];
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
