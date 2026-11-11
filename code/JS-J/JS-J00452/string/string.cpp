#include<bits/stdc++.h>
using namespace std;
int main(){
    fre("string.in","r",stdin);
    fre("string.out","w",stdout);
    long long a[200001],n,b[200000],sum=0,s=0,d[200001];
    char c[200001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        d[i]=c[i]-'a';

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            b[sum]=d[i];
            sum+=1;
        }
    }
    for(int i=0;i<sum/2;i++){
        if(b[i]!=b[sum-1-i]){
            s+=1;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
