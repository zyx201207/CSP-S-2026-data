#include <iostream>
#include <vector>
using namespace std;

int n,m;
int a[500005];
int cnt[300005];
int lst[300005];
vector<int> table;
void cl(int pos){
    while (table.size()>pos){
        lst[table.back()]=-1;
        table.pop_back();
    }
}

int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int st=1;
    for (int task=1;task<=n;task++){
        for (int i=1;i<=m;i++){
            lst[i]=-1;
        }
        for (int i=st;i<=n;i++){
            int cur=a[i];
            if (lst[cur]!=-1){
                cl(lst[cur]);
            }
            table.push_back(cur);
            lst[cur]=table.size()-1;
            // for (int j=0;j<table.size();j++){
            //     if (cur==a[j]){
            //         cl(j);
            //         break;
            //     }
            // }
            // table.push_back(cur);
            // for (int i=1;i<=m;i++){
            //     cout << lst[i] << ' ';
            // }
            // cout << endl;
        }
        for (int j:table){
            // cout << j << ' ';
            cnt[j]++;
        }
        table.clear();
        st++;
        // cout << endl << endl;
    }
    for (int i=1;i<=m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}