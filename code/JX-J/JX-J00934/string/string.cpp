#include<bits/stdc++.h>
using namespace std;
long long n, a[200010], left, right, sum;
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>c[i];
    }
    int left=1,right=n;
    while(left<right){
        if(c[left] == c[right]){
            if(a[left] > a[right]){
                a[left]-=a[right];
                right--;
            }
            else if(a[left] < a[right]){
                a[right]-=a[left];
                left++;
            }
            else{
                left++;
                right--;
            }
        }
        else{
            if(a[left] > a[right]){
                sum+=a[right];
                a[left]-=a[right];
                right--;
            }
            else if(a[left] < a[right]){
                sum+=a[left];
                a[right]-=a[left];
                left++;
            }
            else{
                sum+=a[left];
                left++;
                right--;
            }
        }
    }
    cout<<sum;
    return 0;
}
