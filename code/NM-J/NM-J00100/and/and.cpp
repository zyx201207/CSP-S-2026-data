#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
long long int n,m;
cin>>n>>m;
long long a[100000000];
string w[10000000];
for(int i=0;i<n;i++){
    cin>>a[i];
}



 sort(a[0],a[m],greater<int>);
for(int i=0;i<n;i++){
    int s=a[i];

    while(s){
        w[i]+=s%2;
        s/=2;
    }
}
fclose(stdin);
fclose(stdout);

}
