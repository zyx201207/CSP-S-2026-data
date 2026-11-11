#include <bits/stdc++.h>
using namespace std;
int n,mid;
long long sum,t,cnt;
struct node{
    long long a;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].a >> a[i].c;
        sum+=a[i].a;
    }
    for(int i=1;i<=n;i++){
        t+=a[i].a;
        if(t>=sum/2){
            mid=i;
            break;
        }

    }
    int i=1,j=n;
    while(i<=mid&&j>-mid){
        if(a[i].c!=a[j].c)
            cnt+=min(a[i].a,a[j].a);
        if(a[i].a<a[j].a){
                a[j].a-=a[i].a;
                i++;
        }
        else if(a[i].a>a[j].a){
                a[i].a-=a[j].a;
                j--;
        }
        else i++,j--;
    }
    cout << cnt;
    return 0;
}
