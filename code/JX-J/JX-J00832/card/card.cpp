#include <bits/stdc++.h>
using namespace std;
int n, m;

struct node
{
    int k;
    int id;
}a[50005];
node b[50005];

int ans[30005];
bool cmp(node x,node y){
    if(x.k != y.k){
        return x.k < y.k;
    }
    else return x.id < y.id;
}
int boundary_find(int j, int x)
{
    int l = 1, r = n;
    int ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(b[mid].k > x){
            r = mid - 1;
        }
        else if(b[mid].k < x) l = mid + 1;
        else {ans = mid; break;}
    }
    int i = ans;
    while(b[ans].k == x){
        if(b[ans - 1].k == x && b[ans - 1].id >= j){
            ans--;
        }
        else if(i == ans && b[ans - 1].id <= j){
            if(b[i + 1].k == x && b[i + 1].id <= j)
                i++;
            else return b[i].id;
        }
        else return b[ans].id;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].k;
        a[i].id = i;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1, cmp);
    for(int j = 1;j <= n;j++){
        for(int i = n;i >= j;i--){
            cout << boundary_find(j, a[i].k) << " " << i << " " << j << " " << a[i].k << ", ";
            if(boundary_find(j, a[i].k) == i) ans[a[i].k]++;
            else {ans[a[i].k]++; break;}
        }
    }
    //cout << endl;
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";

    }
    return 0;
}
