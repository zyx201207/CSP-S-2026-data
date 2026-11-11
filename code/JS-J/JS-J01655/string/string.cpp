#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
int n;
ll ans;
ll a[200015],len;
char c[200015];

int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        len+=a[i];
    }
    ll mid=len/2+(len&1);
    int mid_pos=-1;
    ll tmp=0,lst=-1;
    for (int i=1;i<=n;i++){
        lst=tmp;
        tmp+=a[i];
        if (tmp>=mid&&mid_pos==-1){
            mid_pos=i;
            break;
        }
    }
    if (tmp-mid>0){
        for (int i=n;i>mid_pos;i--){
            a[i+1]=a[i];
            c[i+1]=c[i];
        }
        n++;
        a[mid_pos]-=(tmp-mid);
        a[mid_pos+1]=tmp-mid;
        c[mid_pos+1]=c[mid_pos];
    }
    if (lst<mid-1){
        for (int i=n;i>=mid_pos;i--){
            a[i+1]=a[i];
            c[i+1]=c[i];
        }
        n++;
        mid_pos++;
        a[mid_pos-1]=mid-lst-1;
        a[mid_pos]-=a[mid_pos-1];
    }
    int l=1,r=n;
    while (l<=mid_pos&&r>mid_pos){
        if (a[l]<=a[r]){
            if (c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }else {
            if (c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}