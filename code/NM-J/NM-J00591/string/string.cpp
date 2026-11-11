#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,a[200005],l=0,z=0,h=0,q=0,i;
    string c,b;
    cin>>n;
    for(int i=1;i<=n;i++){

        cin>>a[i]>>c;
        l=a[i];

        for(int i=1;i<=l;i++){
            b=b+c;

        }
    }
    z=b.size();
    if(z%2!=0){
        h=z/2+1;
    }else{
        h=z/2;
    }


    if(b[h+i]!=b[h-i]){
        b[h+i]==b[h-i];
        q++;

    }else {
        q=0;

    }



    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
