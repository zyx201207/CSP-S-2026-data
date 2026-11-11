#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        scanf("%s",&a[i].c);
        cnt++;
    }
    int k=1,j=n;
    long long sum=0;
    while(k<=j){
        if(a[k].c!=a[j].c){
            sum+=min(a[k].num,a[j].num);
        }
        if(a[k].num>a[j].num){
            a[k].num-=a[j].num;
            j--;
        }
        else{
            a[j].num-=a[k].num;
            k++;
        }
    }
    cout<<sum;
    return 0;
}


