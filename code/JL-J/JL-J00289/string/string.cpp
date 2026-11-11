#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("string.in","r",stdin);
    freopen ("string .out","w",stdout);
    int n;
    cin>>n;
    int b[100000];
    for(int i=0;i<n;i++){

        cin>>b[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=b[n];

    }
    cout<<cnt-b[2];
    fclose(stdin);
	fclose(stdout);
    return 0;
}
