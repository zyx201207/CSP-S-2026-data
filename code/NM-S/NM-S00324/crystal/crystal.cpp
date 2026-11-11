#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n==1){cout<<1;return 0;}
    vector<long long>a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long z=1,s=1;
    queue<long long>q;
    q.push(a[0]);
    for(long long i=1;i<n;i++){
        m-=s*(a[i]-a[i-1]);
        while(s>0&&m<0){
            s--;
            m+=a[i]-q.front();
            q.pop();
        }
        s++;
        q.push(a[i]);
        z=max(z,s);
    }
    cout<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
