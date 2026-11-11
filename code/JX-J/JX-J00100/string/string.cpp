#include<bits/stdc++.h>
using namespace std;
int n;int cnt;long long ans;char c;
struct node{
    int x;
    char s;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while(n--){
        scanf("%d %c",&a[++cnt].x,&c);
        a[cnt].s=c;
    }
    int i=1,j=cnt;
    while(1){
        if(i>=j){
            break;
        }
        if(a[i].x>a[j].x){
            if(a[i].s!=a[j].s){
                ans+=a[j].x;
            }
            a[i].x-=a[j].x;
            j--;
        }else if(a[i].x<a[j].x){
            if(a[i].s!=a[j].s){
                ans+=a[i].x;
            }
            a[j].x-=a[i].x;
            i++;
        }else if(a[i].x==a[j].x){
            if(a[i].s!=a[j].s){
                ans+=a[i].x;
            }
            i++;
            j--;
        }
    }
    cout << ans;
    return 0;
}
