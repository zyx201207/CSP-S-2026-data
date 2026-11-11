#include<bits/stdc++.h>
using namespace std;
long long n,m,ys[500013],maxx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ys[i];
    }
    if(ys[1]+1==ys[2]){
        for(int i=1,j=1;;j++,i+=j){
            if(m-i<0)break;
            else maxx++;
        }
        cout<<maxx;
        return 0;
    }
    if(abs(ys[2]-ys[1])==abs(ys[3]-ys[2])){
        maxx=(m-1)/abs(ys[2]-ys[1]);
        cout<<maxx;
        return 0;
    }
    sort(ys+1,ys+n+1);
    for(int i=n;i>1;i--){
        int n1=m,m1=i-1;
        long long sum=1;
        while(n1>0&&m1>0){
            n1-=(ys[i]-ys[m1]);
            sum++;
            m1--;
        }
        maxx=max(sum,maxx);
    }
    cout<<maxx;
    return 0;
}
