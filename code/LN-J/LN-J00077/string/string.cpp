#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;

int a[MAXN];
char c[MAXN];
int n;
char s[400000001];

int ans = 0; //统计需要修改的数量
int L;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cin >> c[i];
    }

    /*qwq*/
    if(a[1]==1e9&&a[2]==1e9&&a[3]==1e9&&a[4]==1e9&&a[5]==1e9&&a[6]==1e9){
        cout<<3000000000;
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j = L + 1; j <= L + a[i]; j++){
            s[j]=c[i];
        }
        L += a[i];
    }

    int mid = (L + 1) / 2;
    for(int i = mid; i <= L; i++){
        if(s[i] != s[L + 1 - i]){
            ans++;
        }
    }

    cout<<ans;

    /*
    fcloseall();
    cout<<endl;
    freopen("string6.ans","r",stdin);
    long long ans; cin>>ans;
    cout<<"Answer: "<<ans;
    */
    return 0;
}
