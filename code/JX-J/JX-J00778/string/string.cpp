#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long i,a;
    char c;
    vector<long long> as;
    vector<char> cs;
    bool same=true;
    char l_c;
    for (i=1;i<=n;i++){
        cin>>a>>c;
        if (i!=1 && c!=l_c){
            same = false;
        }
        as.push_back(a);
        cs.push_back(c);
        l_c = c;
    }
    if (same){
        cout << 0;
        return 0;
    }
    long long left=0;
    long long right=n-1;
    long long cnt_l=0;
    long long cnt_r=0;
    long long cnt=0;
    while (left<right){
        if (cs[left]!=cs[right]){
            if (as[left]-cnt_l>as[right]-cnt_r){
                cnt+=as[right]-cnt_r;
                cnt_l+= as[right]-cnt_r;
                cnt_r=0;
                right--;
            } else if (as[left]-cnt_l==as[right]-cnt_r){
                cnt+=as[left]-cnt_l;
                right--;
                left++;
                cnt_l=0;
                cnt_r=0;
            } else {
                cnt+=as[left]-cnt_l;
                cnt_l=0;
                cnt_r+=as[left]-cnt_l;
                left++;
            }
            continue;
        } else {
            if (as[left]-cnt_l>as[right]-cnt_r){

                cnt_l+= as[right]-cnt_r;
                cnt_r=0;right--;
            } else if (as[left]-cnt_l==as[right]-cnt_r){
                right--;
                left++;
                cnt_l=0;
                cnt_r=0;
            } else {

                cnt_l=0;
                cnt_r+=as[left]-cnt_l;left++;
            }
            continue;
        }
    }
    cout << cnt<<endl;
    return 0;
}
