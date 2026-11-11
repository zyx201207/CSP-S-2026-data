#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN=2e5+5;
long long a[MAXN],ans;
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i]>>c[i];}
    int top=1,tail=n;
    while(top<=tail){
        if(c[top]!=c[tail]){
            if(a[top]>a[tail]){
                ans+=a[tail];
                a[top]-=a[tail];
                tail--;
            }else if(a[top]<a[tail]){
                ans+=a[top];
                a[tail]-=a[top];
                top++;
            }else{
                ans+=a[top];
                top++;tail--;
            }
        }else{
            if(a[top]>a[tail]){
                a[top]-=a[tail];
                tail--;
            }else if(a[top]<a[tail]){
                a[tail]-=a[top];
                top++;
            }else{
                top++;tail--;
            }
        }
    }
    cout<<ans;
    return 0;
}
