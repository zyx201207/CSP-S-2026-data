#include<iostream>
#include<string>
using namespace std;
long long n,len,ans;
string sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    sum+='0';
    for(int i=1;i<=n;i++){
        int num=0;
        string c;
        cin>>num>>c;
        len+=num;
        while(num--){
            sum+=c;
        }
    }
    for(int i=1;i<=len/2;i++){
        if(sum[i]!=sum[len-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
