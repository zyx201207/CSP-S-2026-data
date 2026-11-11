#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long ar[500010];
long long num_2 = ar[0];
long long cnt_2 = 1;

struct Number{
    long long num;
    long long cnt;
};

int cmp(long long a,long long b){
    return a < b;
}

int cmp2(Number a,Number b){
    return a.cnt > b.cnt;
}

int cmp3(Number a,Number b){
    if(a.cnt == b.cnt){
        return abs(a.num - num_2) < abs(b.num - num_2);
    }else{
        return a.cnt > b.cnt;
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Number nums[100000];
    cin>>n;
    cin>>m;
    for(int i = 0;i < n;i++){
        cin>>ar[i];
    }
    sort(ar,ar + n,cmp);

    long long k = 0;
    for(int i = 1;i < n;i++){
        if(ar[i] == num_2){
            cnt_2++;
        }else{
            nums[k].num = num_2;
            nums[k].cnt = cnt_2;
            k++;
            num_2 = ar[i];
        }
    }

    sort(nums,nums + k,cmp2);

    num_2 = nums[0].num;
    cnt_2 = nums[0].cnt;

    sort(nums,nums + k,cmp3);

    k = 1;
    int ab_s;
    while(m > 0){
        ab_s = abs(num_2 - nums[k].num);
        if(ab_s <= m){
            m = m - ab_s;
            cnt_2++;
            nums[k].cnt--;
            if(m <= 0){
                break;
            }
            if(nums[k].cnt == 0){
                k++;
            }
        }else{
            break;
        }
    }

    cout<<cnt_2 + 1;
    return 0;
}
