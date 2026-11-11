include<bits/stdc++.h>
using namespace std;
int a[1000000];
int m[1000000];
int cf[100000];
int main(){
int n=0;
cin>>n>>M;
for(int i=1'i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cf[j]=a[j];
        m[j]++;
        if(a[j+1]==cf[j]){

        }

    }
}

return 0;
}




