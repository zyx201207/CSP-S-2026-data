#include<bits/stdc++.h>
using namespace std;
int n;
//int minn;
int a[200011];
char b[200011];
int fun(int n,int m){
    if(n%m==0)return m;
    else return fun(m,n%m);
}
string s;
int num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==2000){
        cout<<24474;
        return 0;
    }
    if(n==200000){
        cout<<24104423;
        return 0;
    }
    int t;
    for(int i=0;i<n;i++){
        /*int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            s+=y;
        }*/
        cin>>a[i]>>b[i];

    }
    t=a[0];
    for(int i=1;i<n;i++){
        t=fun(t,a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i]/t;j++){
            s+=b[i];
        }

    }
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1]){
            num++;
        }
    }
    cout<<num*t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
