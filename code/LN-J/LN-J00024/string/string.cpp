#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);


string s;
int n;
cin>>n;
long long leng(0);
for(int i=1;i<=n;i++){
    int x;char a;
cin>>x>>a;

    for(int k=leng+1;k<=leng+x;k++){
        s[k]=a;
    }
    leng+=x;

}

int sum(0);
for(int i=1;i<=(leng+1)/2;i++){
    if(s[i]!=s[leng+1-i]){
        sum++;
    }
}

cout<<sum;





return 0;
}
