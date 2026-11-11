#include<bits/stdc++.h>
using namespace std;
int da[5001] = {0};
void diao(int begin_,int end_){
    bool na = false;
    for(int i = begin_;i < end_;i++){
        if(da[i] == da[end_]){
            na = true;
        }
        if(na){
            da[i] = 0;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ji[m + 1] = {0};
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            da[j] = a[j];
            diao(i,j);
        }
        for(int j = i;j <= n;j++){
            ji[da[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ji[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}



