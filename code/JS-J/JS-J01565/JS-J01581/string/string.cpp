#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    int len;
    char ch;
}a[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].ch;
    }
    for(int i=1,j=n;;){
        if(i>=j)break;
        if(a[i].ch==a[j].ch){
            if(a[i].len==a[j].len){
                i++;
                j--;
                continue;
            }
            if(a[i].len>a[j].len){
                a[i].len-=a[j].len;
                j--;
                continue;
            }
            a[j].len-=a[i].len;
            i++;
            continue;
        }
        if(a[i].len==a[j].len){
            ans+=a[i].len;
            i++;
            j--;
            continue;
        }
        if(a[i].len<a[j].len){
            ans+=a[i].len;
            a[j].len-=a[i].len;
            i++;
            continue;
        }
        ans+=a[j].len;
        a[i].len-=a[j].len;
        j--;
    }
    cout<<ans;
    return 0;
}
