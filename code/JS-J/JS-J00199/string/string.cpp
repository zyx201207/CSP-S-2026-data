#include<iostream>
using namespace std;
struct str{
    long long start,finish;
    char c;
}a[200005];
long long le=0;
char f(long long ind){
    for(long long i=1;i<=le;i++){
        if(a[i].start<=ind&&ind<=a[i].finish){
            return a[i].c;
        }
    }
    return '\0';
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k>>a[i].c;
        a[i].start=le+1;
        a[i].finish=a[i].start+k-1;
        le+=k;
    }
    le+=1;
    long long cnt=0;
    for(int i=1;i<=le/2;i++){
        if(f(i)!=f(le-i)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
