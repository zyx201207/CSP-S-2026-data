#include<bits/stdc++.h>
using namespace std;
int n;
long long step;
int a[200005];
string b[200005];
int ans=0;
queue<string>q1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        step+=a[i];
    }
    if(step%2==1){
            int f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                f++;
                if(f==(ceil(step/2)+1))continue;
                else if(f>(ceil(step/2)+1)){
                    if(b[i]!=q1.front())ans++;
                    q1.pop();
                }else q1.push(b[i]);
            }
        }
    }else{
        int f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                f++;
                if(f>(step/2)){
                    if(b[i]!=q1.front())ans++;
                    q1.pop();
                }else q1.push(b[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
