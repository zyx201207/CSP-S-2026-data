#include<bits/stdc++.h>
using namespace std;
struct str{
    long long num;
    char s;
};
str t[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    cin>>n;
    int i=0,j=n-1;
    for(int m=0;m<n;m++)
        cin>>t[i].num>>t[i].s;
    while(i==j){
        if(t[i].s!=t[j].s){
            if(t[i].num==t[j].num){
                sum+=t[i].num;
                i++,j--;
            }
            else if(t[i].num>t[j].num){
                sum+=t[j].num;
                t[i].num-=t[j].num;
                j--;
            }
            else{
                sum+=t[i].num;
                t[j].num-=t[i].num;
                i++;
            }
        }
    }
    cout<<sum;
    return 0;
}
