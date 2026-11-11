#include<bits/stdc++.h>
using namespace std;
int n,m;
int max=INT_MIN;
struct BASE{
    int num;
    int oneSum;
}a[200001];

int splitNum(int num){
    int sum=0;
    while(num>0){
        if(num%2==1){
            sum++;
            num--;
            num/=2;
        }
        else num/=2;
    }
    return sum;
}
bool cmp(BASE x,BASE y){
    return x.oneSum>y.oneSum;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        a[i].oneSum=splitNum(a[i].num);
    }
    sort(a+1,a+1+n,cmp);
    cout<< a[m].num ;
    return 0;
}