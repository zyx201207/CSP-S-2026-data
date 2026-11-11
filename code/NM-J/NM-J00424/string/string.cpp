#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    int m[100005];
    string y;
    cin>>a;
    int j=0;
    for(int i=0;i<a;i++){
        int mm;
        cin>>mm;
        for(j=0;j<mm;j++){
            mm=mm+a;
        }
    }
    int sum=0;
    while(a--){
        for(int i=0;i<y.size();i++){
            if(m[i]!=m[j-i]){
                sum++;
                m[j-i]=m[i];
            }
        }
    }
    cout<<sum;
    return 0;
}
