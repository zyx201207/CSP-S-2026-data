#include<bits/stdc++.h>
using namespace std;
int n,a,idx=0,cnt = 0;
char str[100000000],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int i=0;i<a;i++) str[idx++] = c;
    }
    for(int i=0;i<idx/2;i++) if (str[i] != str[idx-i-1]) cnt++;
    cout<<cnt;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,a,idx;
char str[100000050],c;
long long num[100000050];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        str[i] = c;
        num[i] = num[i-1] + a;
        idx += a;
    }
    int l = 1,r = n;
    for(long long i=1;i<=idx/2;i++) {
        while(i > num[l] && l<n) l++;
        char lc = str[l];
        while(idx-i+1 <= num[r-1] && r>1) r--;
        char rc = str[r];
        if (lc != rc) cnt++;
    }

    cout<<cnt;
    return 0;
}
*/

//neng2bu4neng2duo1gei3yi4dian3a0
