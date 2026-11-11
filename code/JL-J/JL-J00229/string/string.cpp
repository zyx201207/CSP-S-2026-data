#include<iostream>
#include<sys/procfs.h>
#include<string>
using namespace std;
int n;
long long a[1000005];
long long ans;
string s;
char s2[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;string y;
        cin>>x>>y;
        a[i]=x;
        s+=y;
    }int cnt=0;
    for(int i=s.size()-1;i>=0;i--){
        s2[cnt]=s[i];
        cnt++;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s2[i]){
            if(a[i]>a[s.size()-i-1]){
                ans+=a[s.size()-i-1];
                s[i]=s[s.size()-i-1];
            }else{
                ans+=a[i];
                s[s.size()-i-1]=s[i];
            }
        }
    }
    cout<<ans;


    return 0;
}

