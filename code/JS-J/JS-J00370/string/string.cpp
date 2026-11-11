#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200011;

int n;
struct node{
    int x;
    char y;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    if(n==1) cout<<0<<"\n";
    else if(n==2){
        int x,y;
        char a,b;
        cin>>x>>a>>y>>b;
        cout<<min(x,y)<<"\n";
    }else{//aabbcbbba
        ll sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y,sum+=a[i].x;
        }
        if(sum%2==0){
            int l=1,r=n;
            while(l!=r-1){
                if(a[l].y==a[r].y){
                    if(a[l].x>a[r].x) a[l].x-=a[r].x,r--;
                    else if(a[l].x<a[r].x) a[r].x-=a[l].x,l++;
                    else l++,r--;
                }
                if(a[l].y!=a[r].y){
                    if(a[l].x>a[r].x) a[l].x-=a[r].x,cnt+=1LL*a[r].x,r--;
                    else if(a[l].x<a[r].x) a[r].x-=a[l].x,cnt+=1LL*a[l].x,l++;
                    else cnt+=1LL*a[l].x,l++,r--;
                }
            }
            if(a[l].y!=a[r].y) cnt++;
            cout<<cnt<<"\n";
        }
        if(sum%2==1){
            int l=1,r=n;
            cnt=0;
            while(l!=r){
                if(a[l].y==a[r].y){
                    if(a[l].x>a[r].x) a[l].x-=a[r].x,r--;
                    else if(a[l].x<a[r].x) a[r].x-=a[l].x,l++;
                    else l++,r--;
                }
                if(a[l].y!=a[r].y){
                    if(a[l].x>a[r].x) a[l].x-=a[r].x,cnt+=1LL*a[r].x,r--;
                    else if(a[l].x<a[r].x) a[r].x-=a[l].x,cnt+=1LL*a[l].x,l++;
                    else cnt+=1LL*a[l].x,l++,r--;
                }
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
