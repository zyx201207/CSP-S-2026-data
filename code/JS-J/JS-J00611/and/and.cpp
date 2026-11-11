#include <iostream>
#define mas 200010
using namespace std;

bool getkbit(int x, int k){
    return x&(1<<k);
}

int n, m, ans;
int last, now;
int onenum[32];
bool isdied[mas];
int a[mas];

void quickadd(int x){
    for (int i=0;i<30;i++)
        if (getkbit(x, i))
            onenum[i]++;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        cin >> a[i];
        quickadd(a[i]);
    }

    last=-1;
    for (int i=29;i>=0;i--){
        if (onenum[i]>=m){
            last=i; break;
        }
    }

    if (last==-1){
        cout << "0" << endl;
        return 0;
    }

    ans=1<<last;

    for (int i=last-1;i>=0;i--){
        int cnt=0;
        for (int j=1;j<=n;j++){
            if (!getkbit(a[j], last)) isdied[j]=1;
            if (isdied[j]) continue;

            cnt+=getkbit(a[j], i);
        }
        if (cnt>=m){
            last=i;
            ans|=(1<<last);
        }
        // for (int dd=1;dd<=n;dd++)
        //     cout << isdied[dd] << " ";
        // cout << "last: " << last << " cnt: " << cnt << endl;
    }

    
    

    cout << ans << endl;

    return 0;
}