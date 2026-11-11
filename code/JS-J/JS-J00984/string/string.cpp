#include<bits/stdc++.h>
using namespace std;
int n;long long sum=0;
struct stu{
    int num;char zm;
} a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].num>>a[i].zm;
    int l=0,r=n-1;
    while(l<r){
        if(a[l].zm==a[r].zm){
            if(a[l].num<a[r].num){
                a[r].num-=a[l].num;
                l++;
            }
            else if(a[l].num==a[r].num){ l++;r--; }
            else if(a[l].num>a[r].num){
                a[l].num-=a[r].num;r--;
            }
        }
        else{
            if(a[l].num<a[r].num){
                a[r].num-=a[l].num;
                sum+=a[l].num;
                l++;
            }
            else if(a[l].num==a[r].num){ sum+=a[l].num;l++;r--; }
            else if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                sum+=a[r].num;
                r--;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
