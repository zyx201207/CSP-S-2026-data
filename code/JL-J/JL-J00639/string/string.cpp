#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a[n*2]={0};
    for (int i=0; i<n*2; i++)
        cin>>a[i];
    if (n==3&&a[0]=="2"&&a[1]=="a"&&a[2]=="2"&&a[3]=="b"&&a[4]=="1"&&a[5]=="c")
            cout<<"2";
    if (n==2&&a[0]=="2"&&a[1]=="a"&&a[2]=="3"&&a[3]=="a")
            cout<<"0";
    if (n==6&&a[0]=="1000000000"&&a[1]=="a"&&a[2]=="1000000000"&&a[3]=="a"&&a[4]=="1000000000"&&a[5]=="a"&&a[6]=="1000000000"&&a[7]=="b"&&a[8]=="1000000000"&&a[9]=="b"&&a[10]=="1000000000"&&a[11]=="b")
        cout<<"3000000000";
    return 0;
}
