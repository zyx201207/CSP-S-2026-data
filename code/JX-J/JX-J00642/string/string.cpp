#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    char a[1000000];
    int n,num,num1=0,x;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        num1+=num;
        num=num1-num;
        cin>>c;
        for(int j=num;j<num1;j++){
            a[j]=c;
            x++;
        }

    }
    int o=0;
    for(int i=0;i<x/2;i++){
        if(a[i]!=a[x-i-1]){
            o++;
        }
    }
    cout<<o;
    return 0;
}

