#include<bits/stdc++.h>
using namespace std;
int arr[600000];
int play[600000];
int sum[600000];
long long capacity = 1;
void check(int num){
    if(capacity == 1){
        return;
    }
    for(int k = 1;k<=capacity;k++){
        if(play[k] == num){
            capacity = k;
            break;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i<=n;i++){
        capacity = 1;
        for(int j = i;j<=n;j++){
            check(arr[j]);
            play[capacity] = arr[j];
            capacity++;
        }
        for(int k = 1;k<capacity;k++){
            sum[play[k]]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout << sum[i] << ' ';
    }
}
