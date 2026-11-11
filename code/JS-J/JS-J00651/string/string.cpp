#include<bits/stdc++.h>
using namespace std;

struct duan{
    int shu;
    char mu;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    duan a[n];
    long long _sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i].shu >> a[i].mu;
        _sum += a[i].shu;
    }
    _sum /= 2;
    long long gai = 0;
    int qian = 0;
    int hou = n - 1;
    while(_sum > 0){
        if(a[qian].shu == 0){
            qian++;
        }
        if(a[hou].shu == 0){
            hou--;
        }
        int b = min(a[qian].shu,a[hou].shu);
        if(a[qian].mu == a[hou].mu){
            _sum -= b;
            a[qian].shu -= b;
            a[hou].shu -= b;
        }else{
            gai += b;
            _sum -= b;
            a[qian].shu -= b;
            a[hou].shu -= b;
        }
    }
    cout << gai;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


