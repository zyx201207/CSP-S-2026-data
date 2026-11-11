#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x[100000];
    string c[100000];
    int n,f[100000];
    int sum=0;
    int  sum2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i]>>c[i];
        sum+=f[i];
        for(int j=0;j<f[i];j++){
            x[j+sum]=c[i];
        }
    }
    for(int i=0;i<=sum/2;i++){
        if(x[i]!=x[sum]){
            sum2++;
            i++;
            sum--;
        }
    }
    cout<<sum2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
