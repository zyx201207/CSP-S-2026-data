#include<bits/stdc++.h>
using namespace std;
char s[200005];
int a[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>s[i];

    }

    long long cnt=0;
    int head=0,hc=0;
    int tail=n-1,tc=0;
    while(head<tail){
        if(hc>=a[head]){
            hc=0;
            head++;
        }
        if(tc>=a[tail]){
            tc=0;
            tail--;
        }
        if(head>=tail) break;
        if(a[head]-hc>a[tail]-tc){
            if(s[head]!=s[tail]) cnt+=a[tail]-tc;
            hc+=a[tail]-tc;

            tc=0;
            tail--;

        }
        else if(a[head]-hc<=a[tail]-tc){
            if(s[head]!=s[tail]) cnt+=a[head]-hc;
            tc+=a[head]-hc;
            hc=0;
            head++;

        }

    }
    cout<<cnt;


    return 0;
}

