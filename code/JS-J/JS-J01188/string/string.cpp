#include<bits/stdc++.h>
using namespace std;
const int N=2000070;
long long k;
int n;
long long a[N];
char c[N];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    bool sss=1;
    char kkk;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        kkk=c[0];
        k+=a[i];
        if(kkk!=c[i])sss=0;

    }
    long long aqq1=0;
    if (sss==1){
        cout<<0;
        return 0;
    }
    else if(k<=10000100){
        char aaaa[10000100];
        int gdsg=0;
        for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
        aaaa[gdsg]=a[i];
        gdsg++;
    }
    }
    int cntttttttt=0;
    for (int i=0;i<k/2+1;i++){
        if (aaaa[i]!=aaaa[k-i]){
            cntttttttt++;
            aaaa[i]=aaaa[k-i];
        }
    }
    cout<<cntttttttt;
    }
    else {
        cout<<0;
    }
    return 0;
}
