#include<bits/stdc++.h>
using namespace std;
char a[1000000001];
int num=0,j=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        int k;
        char x;
        cin>>k>>x;
        for(int i=j;i<k;i++){
            a[i]=x;
        }
        j+=k;
    }
    for(int i=0;i<j;i++){
        if(a[i]!=a[j-i-1]) num++;
    }
    cout<<num/2;
    fclose(stdin);
    fclose(stdout);



    return 0;
}
