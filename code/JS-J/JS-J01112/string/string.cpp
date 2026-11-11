#include<bits/stdc++.h>
using namespace std;
struct Node{
    unsigned long long number;
    char c;
}a[200005];
unsigned long long l,ans;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].number>>a[i].c;
    int i=1,j=n;
    while(i<=j){
        if(a[i].c==a[j].c){
            if(a[i].number>a[j].number){
                a[i].number-=a[j].number;
                a[j].number=0;
                j--;
            }else if(a[i].number==a[j].number){
                a[i].number=0;
                a[j].number=0;
                i++;j--;
            }else{
                a[j].number-=a[i].number;
                a[i].number=0;
                i++;
            }
        }else{
            ans+=min(a[i].number,a[j].number);
            if(a[i].number>a[j].number){
                a[i].number-=a[j].number;
                a[j].number=0;
                j--;
            }else if(a[i].number==a[j].number){
                a[i].number=0;
                a[j].number=0;
                i++;j--;
            }else{
                a[j].number-=a[i].number;
                a[i].number=0;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
