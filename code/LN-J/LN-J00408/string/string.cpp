#include<bits/stdc++.h>
using namespace std;
struct A{
    int number;
    char ch;
}a[200005];
int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].number>>a[i].ch;
    }
    int head=1,tail=n;
    while(head<=tail){
        if(head==tail){
            break;
        }
        if(a[head].number<=a[tail].number&&a[head].ch!=a[tail].ch){
            ans+=a[head].number;
            a[tail].number-=a[head].number;
            head++;
        }else if(a[head].ch!=a[tail].ch){
            ans+=a[tail].number;
            a[head].number-=a[tail].number;
            tail--;
        }else if(a[head].number<=a[tail].number){
            a[tail].number-=a[head].number;
            head++;
        }else{
            a[head].number-=a[tail].number;
            tail--;
        }
    }
    cout<<ans;
    return 0;
}
