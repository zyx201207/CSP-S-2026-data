#include<bits/stdc++.h>
using namespace std;

int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n;
    cin >>n;
    long long temp[n];
    char c[n];
    long long sum=0;
    for(int i=0;i<n;i++){
        cin >>temp[i]>>c[i];
        sum+=temp[i];
    }
    //for(int i=0;i<n;i++) cout<<temp[i]<<" ";
    sum/=2;
    long long pos=sum;
    //cout<<sum;
    long long res=0;
    int temp1=0,temp2=n-1;
    long long ans=0;
    while(temp1!=temp2){
        if(sum-temp[temp1]>=0 && sum-temp[temp2]>=0){
            if(c[temp1]!=c[temp2])
                res+=(int)min(temp[temp1],temp[temp2]);
            sum-=(int)min(temp[temp1],temp[temp2]);
            if(temp[temp1]>temp[temp2]){
                temp[temp1]-=(int)min(temp[temp1],temp[temp2]);
                temp2--;
                continue;
            }
            if(temp[temp1]<temp[temp2]){
                temp[temp2]-=(int)min(temp[temp1],temp[temp2]);
                temp1++;
                continue;
            }
            if(temp[temp1]==temp[temp2]){
                temp1++;
                temp2--;
                continue;
            }
        }else{
            res+=(int)min(temp[temp1],temp[temp2]);
            break;
        }
    }
    if(res>pos){
        cout<<pos;
        return 0;
    }else{
        cout<<res;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
