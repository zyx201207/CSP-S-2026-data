#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a[MAXN];
    char b[MAXN];
    long long lms = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
        lms += a[i];
    }
    long long bi = lms / 2;
    long long ji = 0;
    char chn = b[0];
    long long chn1 = 1;
    char chv = b[n-1];
    long long chv1 = n-2;
    long long li = a[0];
    long long xiao = a[n-1];
    for(int i = 0;i < bi;i++){
        if(chn != chv){
            ji++;
        }
        li--;
        xiao--;
        if(li == 0){
            chn = b[chn1];
            li = a[chn1];
            chn1++;
        }
        if(xiao == 0){
            chv = b[chv1];
            xiao = a[chv1];
            chv1--;
        }
    }
    cout << ji;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
