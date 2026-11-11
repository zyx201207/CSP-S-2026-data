#include<bits/stdc++.h>
using namespace std;
int z1[100000010];
char z2[100];
string aa;
//int cmp(int a1,int b1){
//    return a1>b1;
//}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0,m=0,b=0,cnt=0;
    char a=' ';
    cin >>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a;
        while(b){aa+=a;b--;}

    }


    long long  l=0,r=aa.size()-1;
    while(l<=r){
        if(aa[l]!=aa[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}

