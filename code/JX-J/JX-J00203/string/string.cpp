#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n,s[200005];
long long sum=0,p=0,num[200005],ans;
char a[200005],a1[200005],b1[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    num[1]=0;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i];
        sum+=s[i];
        num[i+1]=num[i]+s[i];

    }
        for(long long i=1;i<=n;i++){
            p+=s[i];
            if(p>=sum/2){
                while (p>=num[i+1]){
                    p--;
                }
                for(long long j=num[i];j<p;j++){
                    s1+=a[j];
                }
                for(long long j=1;j<=i-1;j++){
                    for(int k=1;k<=s[i];k++){
                        s1+=a[j];
                    }
                }
                for(long long j=n;j>=i+1;j--){
                    for(int k=1;k<=s[i];k++){
                        s2+=a[j];
                    }
                }
                for(long long j=num[i+1];j>=p;j--){
                    s2+=a[j-1];
                }
                int k=0;
                for(char a11:s1){
                    k++;
                    a1[k]=a11;
                }
                k=0;
                for(char a22:s2){
                    k++;
                    b1[k]=a22;
                }
                for(long long j=1;j<=p;j++){
                    if(a1[j]!=b1[j]){
                        ans++;
                    }
                }
                cout<<ans;
                return 0;
            }

        }
    return 0;
}
