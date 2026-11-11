#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",stdin);
    freopen("travel.out",stdout);
    int n;
    cin>>n;
    int gh[n+10];
    char jk[n+10];
    for(int i=0;i<n;i++){
        cin>>gh[i]>>jk[i];
    }
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt+=gh[i];
    }
    long long cnt1=0;
    int cnt2=0;
    if(cnt%2==1){
        cnt2=1;
    }
    cnt/=2;
    int p=0;
    for(int i=0;i<n-cnt2;i++){
        if(jk[i]==jk[i+1]){
            cnt1+=0;
        }
        else if(i+1>n-cnt2){
            break;
        }
        else{
            cnt1+=gh[i];
            p=i;
        }
    }
    cout<<cnt1/2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
