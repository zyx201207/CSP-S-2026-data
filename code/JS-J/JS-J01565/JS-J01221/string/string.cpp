#include<bits/stdc++.h>
using namespace std;
//CSP-J AK++

struct node{
    long long h;
    string num;
}a[200005];

long long n,re,sum;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].h>>a[i].num;
    }int right=0,left=n-1;re=a[0].h;
    while(left!=right){
        if(left>right){
            //cout<<re<<" ";
            if(re>a[left].h){
                if(a[left].num!=a[right].num){
                    sum+=min(re,a[left].h);
                    re=abs(re-a[left].h);
                    left--;
                }else{
                    re=abs(re-a[left].h);
                    left--;
                }
            }else{
                if(a[left].num!=a[right].num){
                    sum+=min(re,a[right].h);
                    re=abs(a[right].h-re);
                    right++;
                }else{
                    re=abs(a[right].h-re);
                    right++;
                }
            }//cout<<sum<<" "<<re<<endl;
        }
    }
    cout<<sum;
    return 0;
}
