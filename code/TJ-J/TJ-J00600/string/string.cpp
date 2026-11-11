#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long s=0;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    long long ans=0;
    long long p1=1,p2=n,i=1,j=s;
    while(i<j&&p1<p2){
        long long cnt=0;
        cnt=min(a[p1],a[p2]);
        if(c[p1]!=c[p2]) ans+=cnt;
        a[p1]-=cnt;
        a[p2]-=cnt;
        if(a[p1]<a[p2]) p1+=1;
        else if(a[p1]==a[p2]) p1+=1,p2-=1;
        else p2-=1;
        i+=cnt,j-=cnt;
    }
    cout<<ans<<endl;
}