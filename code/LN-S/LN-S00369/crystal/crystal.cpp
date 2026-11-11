#include<bits/stdc++.h>
using namespace std;

long long det = 1000000000000;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);

    long long n,m;
    cin>>n>>m;
    long long cnt[n - 1];
    for(int i = 0;i < n;i++) cnt[i] = 0;
    //特判
    if(n == 1){
        cout<<"1";
        return 0;
    }
    //输入 + 排序
    long long a[n + 1];
    for(int i = 0;i < n ; i++ )
        cin>>a[i];
    sort(a,a + n);
    //一个的情况
    for(int i = 1;i < n;i++){
        if(a[i] - a[i - 1]<det) det = a[i] - a[i - 1];
    }
    if(m < det){
        cout<<"1";
        return 0;
    }

    //多个呢

    for(int i = 1;i<n;i++){
        int zong = 0;
        for(int j = i - 1;j >=0 ;j--){
            zong = zong + a[i] - a[j];
            if(zong > m){
                cnt[i - 1] = i - j ;
                break;
            }else if(j == 0)  cnt[i - 1] = i + 1;
        }

    }
    sort(cnt,cnt + n - 1);
    cout<<cnt[n - 2];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
