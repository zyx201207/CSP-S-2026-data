#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[555555],c[555555];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int ff=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=i){
            ff=1;
        }
    }
    if(ff==0){
        long long sum=0;
        for(long long i=1;i<=n;i++){
            m-=i;
            if(m<0){
                break;
            }else{
                sum++;
            }
        }
        cout << sum+1;
        return 0;
    }
    sort(a+1,a+1+n);
    int sr=a[2]-a[1],fg=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=sr){
            fg=1;
            break;
        }
    }
    if(fg==0){
        long long sum=0;
        for(long long i=1;i<=n;i++){
            m-=(i*sr);
            if(m<0){
                break;
            }else{
                sum++;
            }
        }
        cout << sum+1;
        return 0;
    }
    int l=a[1],r=a[n];
    int num=0;
    while(l<=r){
        int mid=l;
        l++;
        for(int i=1;i<=n;i++){
            c[i]=abs(a[i]-mid);
        }
        sort(c+1,c+1+n);
        long long jk=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(jk+c[i]>m){
                break;
            }else{
                jk+=c[i];
                sum++;
            }
        }
        num=max(num,sum);
    }
    cout << num;
}
