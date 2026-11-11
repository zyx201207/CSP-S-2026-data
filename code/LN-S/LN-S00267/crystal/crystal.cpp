#include <iostream>
using namespace std;
int main(){
    int m=0,n=0,r=0,q=0;
    long long a(500000);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    qsort(a);
    for(int i=0;i<n;i++){
        if(m!=0){
            a(r)+=1;
            q++;
            m--;
            if(a(r)==a(r+1)&&r+2<=n){
                r+=2;

            }
        }
        break;
    }
    cout<<q;





return 0;
}
