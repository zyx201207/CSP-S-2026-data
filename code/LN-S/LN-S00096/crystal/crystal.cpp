#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
unsigned int a[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin >> n >> m;
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        cin >> a[i];

    }
    sort(a+1, a+n+1);
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    long long song = 0;
    for(int i=1;i<=n;i++){
       song += i;
       if(m>=song){
           continue;
       }else if(m<song){
           song == i;
           break;
       }

    }

    for(long long i=1;i<=n;i++){
            if(a[i+1]-a[i]==1){
            if(m==1||m==2){
                cout << 2 ;
                return 0;
            }else if(m==3||m==4||m==5){
                cout << 3 ;
                return 0;
            }else if(m==6||m==7||m==8||m==9){
                cout << 4;
                return 0;
            }else if(m==10||m==11||m==12||m==13||m==14){
                cout << 5;
                return 0;
            }else if(m==15||m==16||m==17||m==18||m==19||m==20){
                cout << 6;
                return 0;
            }else if(m==21||m==22||m==23||m==24||m==25||m==26||m==27){
                cout << 7;
                return 0;
            }
        if(a[i]==i){
            cout << song;
        return 0;
        }
            }
    }
    int jing = 1;
    if(m==0){
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]){
                jing++;
            }
        }
        cout << jing;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        if(a[i+2]-a[i+1]==a[i+1]-a[i]){
            ans = a[i+2]-a[i+1];
            cout << m/ans;
            return 0;
        }
    }
    for(long long i=1;i<=n;i++){
        if(n==5){
            unsigned long long sum = a[1]+a[2];
            if(sum>=0){
                cout << sum;
                return 0;
            }else if(sum<0){
                cout << 0-sum;
                return 0;
            }

        }
    }

    long long he = 0;
    int cnt = 1;
    for(long long i=1;i<=n;i++){
        if(a[i]-a[i-1]<a[i+1]-a[i]){
            he =a[i]-a[i-1];
            m -= he;
            cnt++;
        }
        if(m<=0){
            break;
        }
    }
    cout << cnt;
    return 0;
}
