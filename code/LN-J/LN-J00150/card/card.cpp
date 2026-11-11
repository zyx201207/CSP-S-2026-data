#include <iostream>

using namespace std;
struct type{
    long long len;
    char b;
}a[200005],x[100005],y[100005];

int main()
{
    int n;
    cin>>n;
    unsigned long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].len>>a[i].b;
        cnt+=a[i].len;
    }
    cout<<cnt;
    unsigned long long former=0;
    int pos=0;
    if(cnt%2==0){
        for(int i=1;i<=n;i++){
            former+=a[i].len;
            if(former>=cnt/2){
                x[i].len=a[i].len-(former-cnt/2);
                x[i].b=a[i].b;
                if(former==cnt/2)
                    pos=i+1;
                else
                    pos=i;
                break;
            }
            else{
                x[i].len=a[i].len;
                x[i].b=a[i].b;
            }
        }
        for(int i=n;i>=1;i--){
            if(i==pos){
                y[n+1-i].len=former-cnt/2;
                y[n+1-i].b=a[i].b;
            }
            else{
                y[n+1-i].len=a[i].len;
                y[n+1-i].b=a[i].b;
            }
        }
    }
    for(int i=1;i<=pos;i++){
        cout<<x[i].b<<x[i].len<<endl;
        cout<<y[i].b<<y[i].len<<endl;
    }
    return 0;
}
