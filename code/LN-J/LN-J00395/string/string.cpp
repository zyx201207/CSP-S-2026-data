#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s1="";
    string s2="";
    string s="";
    int sum=0;
    for(int i=1;i<=n;i++){
        int q1;
        char q2;
        cin>>q1>>q2;
        sum+=q1;
        for(int i=1;i<=q1;i++){
            s+=q2;
        }
    }
    if(sum%2==1){
        int mid=sum/2;
        for(int i=1;i<=mid;i++){
            s1+=s[i-1];
        }
        for(int i=sum;i>=mid+2;i--){
            s2+=s[i-1];
        }
    }
    else{
        int mid=sum/2;
        for(int i=1;i<=mid;i++){
            s1+=s[i-1];
        }
        for(int i=sum;i>=mid+1;i--){
            s2+=s[i-1];
        }
    }
    //cout<<s1<<endl<<s2;
    int mid=sum/2;
    int ans=0;
    //cout<<sum<<endl;
    for(int i=0;i<mid;i++){
        if(s1[i]!=s2[i]) ans++;
    }
    cout<<ans<<endl;
}
