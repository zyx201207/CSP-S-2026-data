#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long chan=0;
    long long cnt[200001];
    string cha[200001];
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> cnt[i] >> cha[i];
    }
    long long l=1;
    long long r = n;
    while(l<=r){
        if (cha[l]==cha[r]){
            if(cnt[l]>cnt[r]){
                cnt[l] -= cnt[r];
                r -= 1;
            }
            else if (cnt[l]==cnt[r]){
                l++;
                r--;
            }
            else{
                cnt[r] -= cnt[l];
                l++;
            }
        }
        else{
            if(cnt[l]>cnt[r]){
                chan += cnt[r];
                cnt[l] -= cnt[r];
                r -= 1;
            }
            else if (cnt[l]==cnt[r]){
                chan+=cnt[l];
                l++;
                r--;
            }
            else{
                chan += cnt[l];
                cnt[r] -= cnt[l];
                l++;
            }
        }
    }
    cout << chan;
    return 0;
}
