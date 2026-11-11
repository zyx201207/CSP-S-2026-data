#include<iostream>;
using namespace std;
int main()
{
    int n,a,sum=0;
    long long b;
    cin>>n;
    for(int i;i<=n;i++){
        cin>>a>>b;
        a+=a;
        if(a%2==1){
            sum=(a-1)/2+1;
        }else{
            sum=a/2+1;
        }
        if("b"=="b"){
            b++;
            sum-1;
        }
    }
    cout<<sum;
    return 0;
}
