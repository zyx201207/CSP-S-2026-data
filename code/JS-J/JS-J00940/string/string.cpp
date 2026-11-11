#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    freopen("string.in", "r", stdin);

    freopen("string.out", "w", stdout);

    long long n, sum = 0;

    cin >> n;

    long long num[n];

    char zifu[n + 1];

    for (int i = 0; i < n; i++){
        cin >> num[i] >> zifu[i];
    }

    long long left = 0, right = n - 1, leftwei = num[0], rightwei = num[n - 1];

    while(right > left){
        if (zifu[left] != zifu[right]){
            sum += min(num[left], num[right]);
            //cout << num[left] << ' ' << num[right] << ' ' << leftwei << ' ' << rightwei << endl;
            if(leftwei < rightwei){
                num[right] -= num[left];
                left++;
                leftwei = num[left] + leftwei;
            }
            else if(rightwei <= leftwei){
                num[left] -= num[right];
                right--;
                rightwei = num[right] + rightwei;
            }
        }
        else {
            if (rightwei < leftwei){
                num[left] -= num[right];
                right--;
                rightwei = num[right] + rightwei;
            }
            else {
                num[right] -= num[left];
                left++;
                leftwei = num[left] + leftwei;
            }
        }
    }

    cout << sum;
    return 0;
}
