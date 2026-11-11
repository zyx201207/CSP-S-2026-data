#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num,max1=INT_MIN;
	cin>>n>>m;
    long long a[100000]={0};
    long long b[100000]={0};
    for(int i=0;i<n;i++){
        cin>>num;
        max1=max(max1,num);
        a[num]=1;
    }
    int num1=0;
    for(int i=max1+1;i>0;i--){
        if(a[i]==1){
            b[num1]=i;
            num1++;
        }
    }
    cout<<b[m-1];
    return 0;
}

