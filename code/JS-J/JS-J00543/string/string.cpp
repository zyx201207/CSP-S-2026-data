#include <bits/stdc++.h>
using namespace std;
int a[1000006],b[1000006];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    cin>>n;
    string s="";
    int f1;
    string s1;
    cin>>f1>>s1;
    a[0]=f1;
    s+=s1;
    for(int i=1;i<n;i++){
        int n2;
        string s2;
        cin>>n2>>s2;
        if(s2[0]==s[i-1]){
            a[i-1]+=n2;
            i--;
            n--;
            continue;
        }
        a[i]=n2;
        s+=s2;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            if(a[i]<=a[s.size()-i-1]){
                s[i]=s[s.size()-i-1];
                sum+=a[i];
            }
            else{
                s[s.size()-i-1]=s[i];
                sum+=a[s.size()-i-1];
            }
        }
    }
    for(int i=0;i<s.size()/2;i++){
        b[i]=abs(a[i]-a[s.size()-i-1]);
    }
    long long gx=0;
    for(int i=0;i<s.size()/2;i++){
        if(gx>=b[i]) gx+=gx-b[i];
        else{
            sum+=b[i]-gx;
            gx=b[i]-gx;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
