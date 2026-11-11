#include<bits/stdc++.h>
using namespace std;
long long ans1;
long long sr[200005][2];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char a;
        cin>>sr[i][0]>>a;
        sr[i][1]=a-'a';
    }
    int l=0,r=n-1;
    while(l<r){
        int a=abs(min(sr[l][0],sr[r][0]));
        if(sr[l][0]>=sr[r][0]){
            sr[l][0]-=sr[r][0];
            sr[r][0]=0;
        }else{
            sr[r][0]-=sr[l][0];
            sr[l][0]=0;
        }
        if(sr[l][1]!=sr[r][1]){
            ans1+=a;
        }
        if(sr[l][0]==0)l++;
        if(sr[r][0]==0)r--;
    }
    cout<<ans1;
    return 0;
}
