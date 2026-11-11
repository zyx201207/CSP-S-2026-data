#include<bits/stdc++.h>
using namespace std;
int main{
freopen("hub.in","r",stdin);
freopen("hub.out","r",stdout);
int a,b,island[1000010]={},th[1000010]={};
bool pr[1000010]={};
cin>>a>>b;
for(int i=0;i<a;i++){
    cin>>island[i];
    if(island[i]>b){
        island[i]=b;
        pr[i]=1;
    }
    }
    int j=0;
    for(int i=0;i<a;i++){
        if(!pr[i]){
            th[j]=i;
            j++;
        }
    }
for(int i=0;i<j;i++){
    cout<<th[j]<<endl;
}



fclose(stdin);
fclose(stdout);
return 0;
}
