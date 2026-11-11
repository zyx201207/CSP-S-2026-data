#include <bits/stdc++.h>
using namespace std;

int andjg(int awa,int qwq){
    stack <int> abc1;
    stack <int> abc2;
    int tmp1 = awa;
    int tmp2 = qwq;
    int lof1 = 0;
    int lof2 = 0;
    while(tmp1 > 0){
        abc1.push(tmp1 % 2);
        tmp1 /= 2;
        lof1++;
    }
    while(tmp2 > 0){
        abc2.push(tmp2 % 2);
        tmp2 /= 2;
        lof2++;
    }
    int abab1 = 0,abab2 = 0;
    for(int wow = 0;wow < lof1;wow++){
        abab1 += abc1.top() * pow(10,wow);
        abc1.pop();
    }
    for(int wow = 0;wow < lof2;wow++){
        abab2 += abc2.top() * pow(10,wow);
        abc2.pop();
    }
    string a1a,a2a,yjg = "";
    a1a = to_string(abab1);
    a2a = to_string(abab2);
    int xh,cc;
    if(a1a.size() > a2a.size()){
        xh = a1a.size();
        cc = a1a.size() - a2a.size();
    }
    else{
        xh = a2a.size();
        cc = a2a.size() - a1a.size();
    }
    for(int wow = xh - 1;wow >= 0;wow--){
        if(a1a.size() > a2a.size()){
            if(a1a[wow] == a2a[wow - cc] && wow - cc >= 0) yjg += '1';
            else yjg += '0';
        }else{
            if(a2a[wow] == a1a[wow - cc] && wow - cc >= 0) yjg += '1';
            else yjg += '0';
        }
    }
    int ggg;
    int qu = 0;
    for(int op = yjg.size() - 1;op >= 0;op--){
        string ttmp = "";
        ttmp += yjg[op];
        int hyw;
        hyw = stoi(ttmp);
        hyw *= pow(2,qu);
        qu++;
        ggg += hyw;
    }
    return ggg;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[200005] = {0};
    int px[200005] = {0};
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        if(i + 1 > n - 1){
            px[i] = andjg(a[i],a[0]);
        }else{
            px[i] = andjg(a[i],a[i+1]);
        }
    }
    sort(px,px + n);
    cout << px[0];
    return 0;
}