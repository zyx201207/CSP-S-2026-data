#include<bits/stdc++.h>
using namespace std;
struct g{
    char c;
    int num;
};
g a[200010];
int t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    int cnt=0;
    while(t--){
        int n;
        char x;
        cin>>n>>x;
        if(x==a[cnt].c){
            a[cnt].num+=n;
        }else{
            cnt++;
            a[cnt].num=n;
            a[cnt].c=x;
        }
    }
    int ans=0;
    for(int i=1,j=cnt;i<j;){
        if(a[i].c==a[j].c){
            if(a[i].num==a[j].num){
                i++;
                j--;
            }
            else if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                j--;
            }else{
                a[j].num-=a[i].num;
                i++;
            }
        }else{
            if(a[i].num==a[j].num){
                ans+=a[i].num;
                i++;
                j--;
            }
            else if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                ans+=a[j].num;
                j--;
            }else{
                a[j].num-=a[i].num;
                ans+=a[i].num;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
