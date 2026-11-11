#include <iostream>
#include <vector>
using namespace std;

int n;
long long a[200005];
char b;
vector<char> s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b>>a[i];
        for (int j=1;j<=a[i];j++){
            s1.push_back(b);
        }
        a[i]+=a[i-1];
    }
    long long length=a[n];
    int cnt=n;
    int cnt2=0;
    for (int i=0;i<length;i++){
        if (a[i]!=a[length-i-1]){
            cnt2++;
        }
    }
    //for (int i==0;a[i]<=length/2;i++){
        //while (length-a[cnt]<=a[i]){
            //cnt--;
        //}
    //}
    cout<<cnt2;
    fclose(stdin);
    fclose(stdout);

}

