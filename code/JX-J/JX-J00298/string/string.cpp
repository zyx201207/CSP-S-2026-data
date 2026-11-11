#include<bits/stdc++.h>
using namespace std;
struct pj{
    long long gs;
    char zm;
};
pj a[200001];
long long n,an=0;
string s,s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].gs>>a[i].zm;
        for(int j=1;j<=a[i].gs;j++){
            s1+=a[i].zm;
        }
    }
    for(int i=0;i<s1.size()/2;i++){
        if(s1[i]!=s1[s1.size()-i-1]){
            s1[s1.size()-i-1]=s1[i];
            an++;
        }
    }
    cout<<an;
    return 0;
}
